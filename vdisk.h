#ifndef VIDK_H
#define VDISK_H

#define VDD int


VDD new_vdisk(char * file, int numsectors);
VDD open_vdisk(char * file, int numsectors);

int write_vdisk(VDD vdisk, int sector, int length, void * data);
int read_vdisk(VDD vdisk, int sector, int length, void * data);


void close_vdisk(VDD vdisk); 


#endif
