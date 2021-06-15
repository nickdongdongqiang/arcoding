#ifndef __DATASOURCE_H__
#define __DATASOURCE_H__

#include <string>

using namespace std;

class DataSource {

    enum {
        SOURCE_FILE = 1,
        SOURCE_MEM,
    };
public:
    DataSource();
    void destroy();

    virtual int source_open() = 0;
    virtual int source_read(uint8_t *buf, int size) = 0; 
    virtual int source_close() = 0;
    virtual int source_seek(int offset, int position) = 0; 
    virtual int source_offset() = 0;
    virtual int source_check_end() = 0;
private:
    virtual ~DataSource();
    string name;
    int type;
    int opened;
    char *priv;
};


#endif