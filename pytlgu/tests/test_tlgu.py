import os
from pytlgu import convert

here = os.path.dirname(os.path.abspath(__file__))
expected_output = """
βλλον δ' ἀλλλους χαλκρεσιν ἐγχεῃσιν.
"""


def test_convert_no_file(capfd):
    convert('goofy', 'non_existent')
    out, err = capfd.readouterr()
    assert(out == '')
    assert('No such file or directory' in err)


def test_convert_no_args(tmpdir):
    infile, outfile = 'tlgu_test.txt', 'output.txt'
    inp = os.path.join(here, infile)
    out = tmpdir.join(outfile)
    convert(inp, out.strpath)
    assert out.read() == expected_output


# # can't assert this - it won't capture the output
# # although it does on my system
# def test_convert_verbose(capfd, tmpdir):
#     infile, outfile = 'tlgu_test.txt', 'output.txt'
#     inp = os.path.join(here, infile)
#     out = tmpdir.join(outfile)
#     convert(inp, out.strpath, verbose=True)
#     out, err = capfd.readouterr()
#     assert(len(out) > 10)
