STR_SIZE = 252

def convert(in_filename,
            out_filename,
            roman=False,
            page=False,
            blank=False,
            acit=False,
            bcit=False,
            ccit=False,
            dcit=False,
            cit_id=False,
            vcit=False,
            wcit=False,
            xcit=False,
            ycit=False,
            cprefix=False,
            ecit_blank=False,
            zcit=False,
            verbose=False,
            debug_bracket=False,
            debug_cit=False,
            debug_special=False,
            multiple=False,
            ebook_cit_x=False,
            ebook_cit_y=False,
            nospace=False,
            cformat='',
            ecite=''):
    """call C tlgu after setting global variables to values passed"""
    # This is extremely ugly, but couldn't script it differently
    # there seems to be no support for global() in cython
    # if it did we could do :
    # for arg in args:
    #     globals()[arg] = locals()[arg.replace('opt_', '')]
    # TODO check if there is a clearer way to do this (maybe with a class?)
    global roman, page, blank, acit, bcit, ccit, dcit, cit_id, vcit, wcit
    global xcit, ycit, cprefix, ecit_blank, zcit, verbose, debug_bracket
    global debug_cit, debug_special, multiple, ebook_cit_x, ebook_cit_y
    global nospace, cformat, ecite
    opt_roman = roman
    opt_page = page
    opt_blank = blank
    opt_acit = acit
    opt_bcit = bcit
    opt_ccit = ccit
    opt_dcit = dcit
    opt_cit_id = cit_id
    opt_vcit = vcit
    opt_wcit = wcit
    opt_xcit = xcit
    opt_ycit = ycit
    opt_cprefix = cprefix
    opt_ecit_blank = ecit_blank
    opt_zcit = zcit
    opt_verbose = verbose
    opt_debug_bracket = debug_bracket
    opt_debug_cit = debug_cit
    opt_debug_special = debug_special
    opt_multiple = multiple
    opt_ebook_cit_x = ebook_cit_x
    opt_ebook_cit_y = ebook_cit_y
    opt_nospace = nospace
    # cformat = bytes(cformat[:STR_SIZE])
    # ecite = bytes(ecite[:STR_SIZE])
    bytes_in_filename = in_filename.encode('utf-8')
    bytes_out_filename = out_filename.encode('utf-8')
    tlgu(bytes_in_filename, bytes_out_filename)
