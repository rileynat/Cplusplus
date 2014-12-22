int fs_rename(char* a, char* b) {
    
    unsigned int a_inode_index = FS_MAXFILEBLOCKS;
    unsigned int b_inode_index = FS_MAXFILEBLOCKS;
    unsigned int a_dir_index = FS_DIRENTRIES;
    fs_direntry dir_block[FS_DIRENTRIES];
    fs_direntry dir_a[FS_DIRENTRIES];
    fs_direntry dir_b[FS_DIRENTRIES];

    for ( int i = 0; i < dir_inode.size / FS_BLOCKSIZE; i++ ) {
        disk_readblock(dir_inode.blocks[i], dir_block);
        for ( int j = 0; j < FS_DIRENTRIES; j++ ) {
            if ( dir_block[j].inode_block != 0 ) {
                if ( strcmp(dir_block[j].name, a) ) {
                    a_inode_index = i;
                    a_dir_index = j;
                    memcpy(dir_a, dir_block, FS_BLOCKSIZE);
                    strcpy(dir_a[j].name, b);
                }
                if ( strcmp(dir_block[j].name, b) ) {
                    b_inode_index = i;
                    memcpy(dir_b, dir_block, FS_BLOCKSIZE);
                    mark_all_file_blocks_free(dir_b[j].inode_block);
                    dir_b[j].inode_block = 0;
                }
            }
        }
        if ( a_inode_index != FS_MAXFILEBLOCKS && b_inode_index != FS_MAXFILEBLOCKS 
            && a_inode_index == b_inode_index ) {
            strcpy(dir_b[a_dir_index].name, b);
            disk_writeblock(dir_inode.blocks[b_inode_index], dir_b);
            return 0;
        }
    }

    if ( a_inode_index == FS_MAXFILEBLOCKS ) {
        return -1;
    }
    if ( b_inode_index == FS_MAXFILEBLOCKS ) {
        disk_writeblock(dir_inode.blocks[a_inode_index], dir_a);
        return 0;
    }
    
    unsigned int old_a_dir_block = dir_inode.blocks[a_inode_index];
    unsigned int old_b_dir_block = dir_inode.blocks[b_inode_index];
    unsigned int new_a_dir_block = get_free_block();
    unsigned int new_b_dir_block = get_free_block();
    dir_inode.blocks[a_inode_index] = new_a_dir_block;
    dir_inode.blocks[b_inode_index] = new_b_dir_block;
    disk_writeblock(new_a_dir_block, dir_a);
    disk_writeblock(new_b_dir_block, dir_b);
    disk_writeblock(dir_inode, 0);
    mark_block_free(old_a_dir_block);
    mark_block_free(old_b_dir_block);

    return 0;

}