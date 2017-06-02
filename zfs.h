/* C wrappers around some zfs calls and C in general that should simplify
 * using libzfs from go language, make go code shorter and more readable.
 */

#ifndef SERVERWARE_ZFS_H
#define SERVERWARE_ZFS_H

struct dataset_list {
	zfs_handle_t *zh;
	void *pnext;
};

typedef struct dataset_list dataset_list_t;
typedef struct dataset_list* dataset_list_ptr;


dataset_list_t *create_dataset_list_item();
void dataset_list_close(dataset_list_t *list);
void dataset_list_free(dataset_list_t *list);

int dataset_list_root(libzfs_handle_t *libzfs, dataset_list_ptr *first);
int dataset_list_children(zfs_handle_t *zfs, dataset_list_ptr *first);
dataset_list_t *dataset_next(dataset_list_t *dataset);

int read_dataset_property(zfs_handle_t *zh, property_list_t *list, int prop);
int read_user_property(zfs_handle_t *zh, property_list_t *list, const char* prop);

int clear_last_error(libzfs_handle_t *libzfs);

char** alloc_cstrings(int size);
void strings_setat(char **a, int at, char *v);

#endif
/* SERVERWARE_ZFS_H */
