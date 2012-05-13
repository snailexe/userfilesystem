#ifndef UFS_H
#define UFS_H

#define BIT  unsigned 
#define DISK_LBA int //basically the location within the file to seek too
#define BOOLEAN int


#define BLOCK_SIZE_BYTES 4096
#define MAX_FILE_NAME_SIZE 15 //max file name size 15 chars
#define MAX_BLOCKS_PER_FILE  100
#define MAX_FILES_PER_DIRECTORY 100

#define BIT_MAP_SIZE (BLOCK_SIZE_BYTES/sizeof(BIT))
#define NUM_INODE_BLOCKS 5


#define SUPERBLOCK_BLOCK 0
#define BIT_MAP_BLOCK 1
#define DIRECTORY_BLOCK 2
#define INODE_BLOCK 3


typedef struct superblock {
  int size_of_super_block;
  int size_of_directory;
  int size_of_inode;

  int disk_size_blocks;
  int num_free_blocks;

  int block_size_bytes;
  int max_file_name_size;
  int max_blocks_per_file;

  BOOLEAN clean_shutdown; //if true can assume numFreeBlocks is valid

} superblock;

typedef struct i_node{
  int no_blocks;
  int file_size_bytes;
  time_t last_modified; // optional add other information
  DISK_LBA  blocks[MAX_BLOCKS_PER_FILE];
  BOOLEAN free;
}inode;

#define INODES_PER_BLOCK (BLOCK_SIZE_BYTES/sizeof(inode))
#define MAX_INODES (INODES_PER_BLOCK * NUM_INODE_BLOCKS)


typedef struct file_struct{
  int  inode_number;
  char file_name[MAX_FILE_NAME_SIZE+1];
  BOOLEAN free;
}file_struct;

typedef struct dir_struct{
  int no_files;
  file_struct u_file[MAX_FILES_PER_DIRECTORY];
}dir_struct;

int u_import(char* linux_file, char* u_file);

int u_export(char* u_file, char* linux_file);

int u_quota();

int u_del(char* u_file);

int u_fsck();

int u_clean_shutdown();

void u_ls();

int u_format(int disk_size, char* file_name);

int recover_file_system(char *file_name);

void init_bit_map();

void free_block(int blockNum);
void allocate_block(int blockNum);

void init_dir();
void init_superblock();

#endif
