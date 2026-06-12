// @BAKE gcc -o $*.out $@ -Wall -Wpedantic -ggdb
#define SLURP_IMPLEMENTATION 
#include <chad/slurp.h>
#define SYNTAX_IMPLEMENTATION 
#include "syntax/syntax.h"

#define RED     "${RED}"
#define GREEN   "${GREEN}"
#define YELLOW  "${YELLOW}"
#define BLUE    "${BLUE}"
#define MAGENTA "${MAGENTA}"
#define RST     "${RST}"

const char * special = "-:*()/.,";

const char * keywords[] = {
    "qckcmd",
    "Qckcmd",
    NULL,
};

const char * link_keywords[] = {
    "https",
    "github",
    "com",
    "agvxov",
    NULL,
};

signed main(int argc, char * argv[]) {
    if (argc != 2) {
        return 1;
    }

    char * input = slurp(argv[1]);

    size_t n = strlen(input);
    n *= 2;

    char buffer[n];

    syntax_init();
    syntax_define_chars(special, YELLOW, RST);
    syntax_define_keywords(keywords, BLUE, RST);
    syntax_define_keywords(link_keywords, RED, RST);
    syntax_define_region("[", "]", "", MAGENTA, RST);
    syntax_define_region("<", ">", "", MAGENTA, RST);
    syntax_define_region(">", "\n", "", RED, RST);
    syntax_define_region("`", "`", "", GREEN, RST);

    syntax_highlight_string(buffer, input, n);

    syntax_deinit();

    puts(buffer);

    return 0;
}
