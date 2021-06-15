#ifndef __BITSTREAM_H__
#define __BITSTREAM_H__

#include <stdint.h>

class bitstream {


private:
    uint8_t *byte_buf;
    uint32_t byte_buf_size;
    uint32_t byte_buf_avail;

    uint32_t read_index;
    uint32_t bit_index;

    uint32_t advance;
    uint32_t advance_offset;

    uint32_t read_index_advance;
    uint32_t bit_index_advance;
    uint8_t *byte_buf_advance;
    uint32_t byte_buf_avail_advance;
    uint32_t byte_buf_size_advance;

    uint32_t *bits;
    uint32_t bits_size;
    uint32_t byte4_size;
    uint32_t bit;

    DataSource *src;
    void *priv;
};

#endif