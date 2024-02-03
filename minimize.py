import re
import subprocess

from common import CONFIG_OPTS


opts = []
for line in open("config"):
    line = line.strip()
    if line and not line.startswith("#"):
        if line not in CONFIG_OPTS:
            print(f"Invalid key-value combination {line}")
            raise SystemExit(1)
        opt = CONFIG_OPTS[line]
        if opt:
            opts.append(opt)


blazingio = open("blazingio.hpp").read()

# Preprocess
blazingio = re.sub(r"^#", "cpp#", blazingio, flags=re.M)
blazingio = re.sub(r"^cpp#   ", "#", blazingio, flags=re.M)
proc = subprocess.run(
    ["cpp", "-P", "-DMINIMIZE"] + [f"-D{opt}" for opt in opts],
    input=blazingio.encode(),
    capture_output=True,
    check=True,
)
blazingio = proc.stdout.decode()
blazingio = re.sub(r"^cpp#", "#", blazingio, flags=re.M)

# Remove unnecessary parentheses
proc = subprocess.run(
    ["clang-format-18", "--style=file:minimize.clang-format"],
    input=blazingio.encode(),
    capture_output=True,
    check=True,
)
blazingio = proc.stdout.decode()

# Replace "return *this;"
blazingio = "#define $r return*this;\n" + re.sub(r"return\s*\*this;", "$r", blazingio)

# Replace "operator"
blazingio = "#define $O operator\n" + blazingio.replace("operator", "$O")

# Strip out comments
blazingio = re.sub(r"//.*", "", blazingio)


# Remove unnecessary whitespace
def whitespace(s):
    if s.startswith("#"):
        s, *rest = s.split(None, 1)
        if rest:
            s += " " + whitespace(rest[0])
        return s
    for _ in range(3):
        s = re.sub(r"([^a-zA-Z0-9_$])\s+(\S)", r"\1\2", s)
        s = re.sub(r"(\S)\s+([^a-zA-Z0-9_$])", r"\1\2", s)
    s = s.replace("\n", " ")
    s = s.replace("''", "' '")
    s = s.strip()
    if s:
        s += "\n"
    return s


blazingio = "".join(whitespace(part) for part in re.split(r"(#.*)", blazingio))

# Remove whitespace after "#include"
blazingio = re.sub(r"#include\s+", "#include", blazingio)


# Replace character literals with their values
blazingio = re.sub(
    r"(?<!<<)(?<!print\()('\\?.')", lambda match: str(ord(eval(match[1]))), blazingio
)


def repl(s):
    # Replace identifiers
    for old, new in [
        ("blazingio_istream", "$i"),
        ("blazingio_ostream", "$o"),
        ("blazingio_ignoreostream", "$e"),
        ("blazingio_cin", "i$"),
        ("blazingio_cout", "o$"),
        ("blazingio_cerr", "e$"),
        ("blazingio_init", "t$"),
        ("ensure", "E$"),
        ("blazingio", "$f"),
        ("SIMD", "$s"),
        ("INLINE", "$I"),
        ("FETCH", "$F"),
        ("typename", "class"),
        ("UninitChar", "A"),
        ("NonAliasingChar", "B"),
        ("buffer", "C"),
        ("space", "D"),
        ("init_assume_file", "E"),
        ("print", "F"),
        ("again", "G"),
        ("collect_digits", "H"),
        ("do_init", "I"),
        ("stream", "J"),
        ("ptr", "K"),
        ("init_assume_interactive", "L"),
        ("file_size", "M"),
        ("base", "N"),
        ("end", "l"),
        ("value", "O"),
        ("abs", "P"),
        ("coeff", "Q"),
        ("interval", "R"),
        ("MinDigits", "S"),
        ("MaxDigits", "U"),
        ("decimal_lut", "V"),
        ("write_int_split", "W"),
        ("whole", "X"),
        ("func", "Y"),
        ("act", "Z"),
        ("info", "a"),
        ("line_t", "b"),
        ("start", "d"),
        ("line", "e"),
        ("exponent", "f"),
        ("low_digits", "g"),
        ("Factor", "h"),
        ("computed", "j"),
        ("n_written", "k"),
        ("negative", "l"),
        ("exps", "m"),
        ("after_dot", "o"),
        ("vec1", "q"),
        ("vec2", "r"),
        ("vec", "s"),
        ("mask", "t"),
        ("input", "u"),
        ("iov", "v"),
        ("Interactive", "w"),
        ("n_read", "y"),
        ("rax", "q"),
        ("Inner", "q"),
        ("empty_fd", "U"),
        ("write12", "w"),
        ("new_exponent", "k"),
        ("rsi", "k"),
        ("file", "k"),
        ("interactive", "w"),
        ("rshift_impl", "t"),
        ("real_part", "w"),
        ("imag_part", "q"),
        ("istream_impl", "q"),
        ("ONE_BYTES", "Z"),
        ("BITSET_SHIFT", "q"),
        ("BIG", "k"),
        ("NULL", "0"),
        ("false", "0"),
        ("true", "1"),
        ("MAP_FAILED", "(void*)-1"),
    ]:
        s = re.sub(r"\b" + re.escape(old) + r"\b", new, s)

    # Replace libc constants
    consts = {
        "O_RDONLY": 0,
        "O_RDWR": 2,
        "PROT_READ": 1,
        "PROT_WRITE": 2,
        "MAP_SHARED": 1,
        "MAP_PRIVATE": 2,
        "MAP_FIXED": 0x10,
        "MAP_ANONYMOUS": 0x20,
        "MAP_NORESERVE": 0x4000,
        "MAP_POPULATE": 0x8000,
        "MADV_POPULATE_READ": 22,
        "MADV_POPULATE_WRITE": 23,
        "SA_SIGINFO": 4,
        "STDIN_FILENO": 0,
        "STDOUT_FILENO": 1,
        "SEEK_END": 2,
        "SPLICE_F_GIFT": 8,
        "SIGBUS": 7,
        "SYS_read": 0,
    }
    const = "(" + "|".join(consts) + ")"
    s = re.sub(
        const + r"(\|" + const + ")*", lambda match: str(eval(match[0], consts)), s
    )

    return s


blazingio = "".join(
    repl(part) if part[0] != '"' else part for part in re.split(r"(\".*?\")", blazingio)
)

# Replace hexadecimal integer literals
blazingio = re.sub(
    r"0x([0-9a-f]+)",
    lambda match: str(int(match[0], 16))
    if len(str(int(match[0], 16))) < 2 + len(match[1].lstrip("0"))
    else "0x" + match[1].lstrip("0"),
    blazingio,
)

# Replace SIMD intrinsics
if "_mm256_" in blazingio:
    blazingio = "#define M$(x,...)_mm256_##x##_epi8(__VA_ARGS__)\n" + re.sub(
        r"_mm256_(\w+)_epi8\(", r"M$(\1,", blazingio
    )
    blazingio = "#define L$(x)_mm256_loadu_si256(x)\n" + blazingio.replace(
        "_mm256_loadu_si256(", "L$("
    )
elif "_mm_" in blazingio:
    blazingio = "#define M$(x,...)_mm_##x##_epi8(__VA_ARGS__)\n" + re.sub(
        r"_mm_(\w+)_epi8\(", r"M$(\1,", blazingio
    )
    blazingio = "#define L$(x)_mm_loadu_si128(x)\n" + blazingio.replace(
        "_mm_loadu_si128(", "L$("
    )

blazingio = blazingio.strip()

# Add comments
blazingio = f"// DO NOT REMOVE THIS MESSAGE. The mess that follows is a compressed build of\n// https://github.com/purplesyringa/blazingio. Refer to the repository for\n// a human-readable version and documentation.\n// Config options: {' '.join(opts) if opts else '(none)'}\n{blazingio}\n// End of blazingio\n"

open("blazingio.min.hpp", "w").write(blazingio)

print("Wrote", len(blazingio), "bytes to blazingio.min.hpp")
