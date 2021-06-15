#ifndef _FILESOURCE_H__
#define _FILESOURCE_H__


#include "DataSource.h"

class FileSource: public DataSource
{
public:
    FileSource *create(string &url, uint32_t size);
    FileSource();
    void destroy();

    virtual int source_open() override;
    virtual int source_read(uint8_t *buf, int size) override;
    virtual int source_close() override;
    virtual int source_seek(int offset, int position) override;
    virtual int source_offset() override;
    virtual int source_check_end() override;

private:
   virtual ~FileSource();

   string m_file;
   FILE *m_fp;

};



#endif