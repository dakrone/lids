#if DEBUG
#define INDENT_MAX 51
static const char __indent_string[INDENT_MAX+3] = "| | | | | | | | | | | | | | | | | | | | | | | | | \0\0\0";
static const char *indent = __indent_string + INDENT_MAX;

#define IN() INf("");
#define INf(fmt,args...) do{\
        fprintf(stderr,"%s,-< %s:%d " fmt "\n", indent, __FUNCTION__, __LINE__, ## args);\
        if ((indent-2) >= __indent_string) indent-=2;\
} while(0)

#define OUT() OUTf("")
#define OUTp(ptr) OUTf("= %p",ptr)
#define OUTd(num) OUTf("= %d",num)
#define OUTf(fmt,args...) do{\
        if (indent <= __indent_string+INDENT_MAX) indent+=2;\
        fprintf(stderr,"%s`-> %s:%d " fmt "\n", indent, __FUNCTION__, __LINE__, ## args);\
} while(0)
#else
#define IN(); /* nothing */
#define INf(f,args...); /* nothing */
#define OUT(); /* nothing */
#define OUTp(p); /* nothing */
#define OUTd(d); /* nothing */
#define OUTf(f,args...); /* nothing */
#endif
