#ifndef REGISTRY_H
#define REGISTRY_H

typedef enum
{
    REGISTRY_SUCCESS,
    REGISTRY_ALLOCATION_ERROR,
    REGISTRY_KEY_LIMIT_EXCEEDED,
    REGISTRY_KEY_NOT_FOUND
} RegistryStatus;

typedef struct
{
    char *key;
    void *value;
} Entry;

typedef struct
{
    Entry *data;
    int size;
    int capacity;
} Registry;

// Public API
Registry *registry_create();
RegistryStatus registry_add(Registry *registry, const char *key, void *value);
void *registry_get(Registry *registry, const char *key);
RegistryStatus registry_remove(Registry *registry, const char *key);
void registry_free(Registry *registry);

#endif // REGISTRY_H
