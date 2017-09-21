#include <stdio.h>

#define ds(v) printf(#v " = %s\n", v)
#define di(v) printf(#v " = %d\n", v)

int main(void) {
    di(__LINE__);
    ds(__FILE__);
    ds(__DATE__);
    ds(__TIME__);
    di(__STDC__);

    // C99
    di(__STDC_HOSTED__);
    di(__STDC_VERSION__);
    di(__STDC_IEC_559__);
    di(__STDC_IEC_559_COMPLEX__);
    di(__STDC_ISO_10646__);
    return 0;
}
