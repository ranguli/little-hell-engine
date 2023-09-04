#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "registry.h"
#include "log.h"

const uint8_t INITIAL_CAPACITY = 10;
const uint8_t MAX_KEY_LENGTH = 255;

// Private functions
static RegistryStatus resize_if_needed(Registry *registry)
{
    if (registry->size >= registry->capacity)
    {
        int new_capacity = registry->capacity * 2;
        Entry *new_data = realloc(registry->data, new_capacity * sizeof(Entry));
        if (!new_data)
        {
            return REGISTRY_ALLOCATION_ERROR;
        }
        registry->data = new_data;
        registry->capacity = new_capacity;
    }
    return REGISTRY_SUCCESS;
}

// Public functions
Registry *registry_create()
{
    log_trace("registry_create(): Initializing a new Registry");

    Registry *registry = malloc(sizeof(Registry));

    if (!registry)
    {
        log_error("registry_create(): Failure: Memory allocation for Registry failed.");
        return NULL;
    }

    registry->data = malloc(INITIAL_CAPACITY * sizeof(Entry));

    if (!registry->data)
    {
        log_error("registry_create(): Failure: Memory allocation for Registry data failed.");
        log_debug("registry_create(): Freeing registry");
        free(registry);
        return NULL;
    }

    registry->size = 0;
    registry->capacity = INITIAL_CAPACITY;
    return registry;
}

RegistryStatus registry_add(Registry *registry, const char *key, void *value)
{
    if (strlen(key) >= MAX_KEY_LENGTH)
    {
        return REGISTRY_KEY_LIMIT_EXCEEDED;
    }

    for (int i = 0; i < registry->size; i++)
    {
        if (strcmp(registry->data[i].key, key) == 0)
        {
            registry->data[i].value = value;
            return REGISTRY_SUCCESS;
        }
    }

    RegistryStatus status = resize_if_needed(registry);
    if (status != REGISTRY_SUCCESS)
    {
        return status;
    }

    registry->data[registry->size].key = strdup(key);
    if (!registry->data[registry->size].key)
    {
        return REGISTRY_ALLOCATION_ERROR;
    }

    registry->data[registry->size].value = value;
    registry->size++;
    return REGISTRY_SUCCESS;
}

void *registry_get(Registry *registry, const char *key)
{
    for (int i = 0; i < registry->size; i++)
    {
        if (strcmp(registry->data[i].key, key) == 0)
        {
            return registry->data[i].value;
        }
    }
    return NULL;
}

RegistryStatus registry_remove(Registry *registry, const char *key)
{
    for (int i = 0; i < registry->size; i++)
    {
        if (strcmp(registry->data[i].key, key) == 0)
        {
            free(registry->data[i].key);

            for (int j = i; j < registry->size - 1; j++)
            {
                registry->data[j] = registry->data[j + 1];
            }

            registry->size--;
            return REGISTRY_SUCCESS;
        }
    }
    return REGISTRY_KEY_NOT_FOUND;
}

void registry_free(Registry *registry)
{
    for (int i = 0; i < registry->size; i++)
    {
        free(registry->data[i].key);
    }
    free(registry->data);
    free(registry);
}
