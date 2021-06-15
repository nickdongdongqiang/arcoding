
#include "FileSource.h"



FileSource::create()

int FileSource::source_open() 
{
    char *file = NULL;
    struct file_priv *f_priv = NULL;

    if (!src)
        return -1;

    f_priv = (struct file_priv *)src->priv;
    if (!f_priv) {
        fprintf(stderr, "fail to malloc file priv-%s-%d\n", __FILE__, __LINE__);
        return -1;
    }

    f_priv->fp = fopen(f_priv->file, "rb");
    if (!f_priv->fp) {
        fprintf(stderr, "open file fail:%s -%s-%d\n", file, __FILE__, __LINE__);
        return -1;
    }

    src->opened = 1;

    return 0;
}