# expose command line arguments to python api
cdef extern from "greek_software_tlgu/tlgu.h":
    bint opt_roman
    bint opt_page
    bint opt_blank
    bint opt_acit
    bint opt_bcit
    bint opt_ccit
    bint opt_dcit
    bint opt_cit_id
    bint opt_vcit
    bint opt_wcit
    bint opt_xcit
    bint opt_ycit
    bint opt_cprefix
    bint opt_ecit_blank
    bint opt_zcit
    bint opt_verbose
    bint opt_debug_bracket
    bint opt_debug_cit
    bint opt_debug_special
    bint opt_multiple
    bint opt_ebook_cit_x
    bint opt_ebook_cit_y
    bint opt_nospace
    # char cformat[253];
    # char ecite[253];
    void tlgu(char *in_filename, char *out_filename)
