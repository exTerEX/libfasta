# libfasta

A C++ library for working with fasta files. The library structure the file as objects. A header and a sequence are stored in a block container, while the entire file is stored in a fasta container. The library use a STL like interface, trying to conform to how _std::vector_ interface.

## Concept / Code

This is a short explanation of behaviour and concepts used in the program.

### Data structure

As explained, the file is stored in a object as objects. The file is segmented into blocks, where each block contain a header, a comment and a sequence. Using the fasta file of **7DDP** from [rcsb.org](https://www.rcsb.org) as an example:

```
>7DDP_1|Chain A|Angiotensin-converting enzyme 2|Homo sapiens (9606)
STIEEQAKTFLDKFNHEAEDLFYQSSLASWNYNTNITEENVQNMNNAGDKWSAFLKEQSTLAQMYPLQEIQNLTVKLQL
QALQQNGSSVLSEDKSKRLNTILNTMSTIYSTGKVCNPDNPQECLLLEPGLNEIMANSLDYNERLWAWESWRSEVGKQL
RPLYEEYVVLKNEMARANHYEDYGDYWRGDYEVNGVDGYDYSRGQLIEDVEHTFEEIKPLYEHLHAYVRAKLMNAYPSY
ISPIGCLPAHLLGDMWGRFWTNLYSLTVPFGQKPNIDVTDAMVDQAWDAQRIFKEAEKFFVSVGLPNMTQGFWENSMLT
DPGNVQKAVCHPTAWDLGKGDFRILMCTKVTMDDFLTAHHEMGHIQYDMAYAAQPFLLRNGANEGFHEAVGEIMSLSAA
TPKHLKSIGLLSPDFQEDNETEINFLLKQALTIVGTLPFTYMLEKWRWMVFKGEIPKDQWMKKWWEMKREIVGVVEPVP
HDETYCDPASLFHVSNDYSFIRYYTRTLYQFQFQEALCQAAKHEGPLHKCDISNSTEAGQKLFNMLRLGKSEPWTLALE
NVVGAKNMNVRPLLNYFEPLFTWLKDQNKNSFVGWSTDWSPYAD
>7DDP_2|Chain B[auth C]|Spike protein S1|Pangolin coronavirus (2708335)
RVQPTISIVRFPNITNLCPFGEVFNASKFASVYAWNRKRISNCVADYSVLYNSTSFSTFKCYGVSPTKLNDLCFTNVYA
DSFVVKGDEVRQIAPGQTGVIADYNYKLPDDFTGCVIAWNSVKQDALTGGNYGYLYRLFRKSKLKPFERDISTEIYQAG
STPCNGQVGLNCYYPLERYGFHPTTGVNYQPFRVVVLSFELLNGPATVCGP
```

This fasta file only contain blocks without comments and when this file is read it would split the file into:

> block 1:

```
>7DDP_1|Chain A|Angiotensin-converting enzyme 2|Homo sapiens (9606)
STIEEQAKTFLDKFNHEAEDLFYQSSLASWNYNTNITEENVQNMNNAGDKWSAFLKEQSTLAQMYPLQEIQNLTVKLQL
QALQQNGSSVLSEDKSKRLNTILNTMSTIYSTGKVCNPDNPQECLLLEPGLNEIMANSLDYNERLWAWESWRSEVGKQL
RPLYEEYVVLKNEMARANHYEDYGDYWRGDYEVNGVDGYDYSRGQLIEDVEHTFEEIKPLYEHLHAYVRAKLMNAYPSY
ISPIGCLPAHLLGDMWGRFWTNLYSLTVPFGQKPNIDVTDAMVDQAWDAQRIFKEAEKFFVSVGLPNMTQGFWENSMLT
DPGNVQKAVCHPTAWDLGKGDFRILMCTKVTMDDFLTAHHEMGHIQYDMAYAAQPFLLRNGANEGFHEAVGEIMSLSAA
TPKHLKSIGLLSPDFQEDNETEINFLLKQALTIVGTLPFTYMLEKWRWMVFKGEIPKDQWMKKWWEMKREIVGVVEPVP
HDETYCDPASLFHVSNDYSFIRYYTRTLYQFQFQEALCQAAKHEGPLHKCDISNSTEAGQKLFNMLRLGKSEPWTLALE
NVVGAKNMNVRPLLNYFEPLFTWLKDQNKNSFVGWSTDWSPYAD
```

> block 2:

```
>7DDP_2|Chain B[auth C]|Spike protein S1|Pangolin coronavirus (2708335)
RVQPTISIVRFPNITNLCPFGEVFNASKFASVYAWNRKRISNCVADYSVLYNSTSFSTFKCYGVSPTKLNDLCFTNVYA
DSFVVKGDEVRQIAPGQTGVIADYNYKLPDDFTGCVIAWNSVKQDALTGGNYGYLYRLFRKSKLKPFERDISTEIYQAG
STPCNGQVGLNCYYPLERYGFHPTTGVNYQPFRVVVLSFELLNGPATVCGP
```

These blocks (stored in the datatype `block_t`) would then be stored in the fasta object (as datatype `fasta_t`).

### Read/Write behavior

When reading a file, the program use the following identifier [1]:

| Line value | Identifier [1] |
| ---------- | -------------- |
| Header     | > or ;         |
| Comment    | ;              |
| Sequence   |                |

**NOTE**: The parser can only distinguish between a header and a comment if the comment follow after the header without the sequence in between and starts with ; at each new line of the comment. Example:

```
>7DDP
; This is an example file showing how a comment could be written into a fasta
; file over multiple lines and still be parsed correctly.
TPKHLKSIGLLSPDFQEDNETEINFLLKQALTIVGTLPFTYMLEKWRWMVFKGEIPKDQWMKKWWEMKREIVGVVEPVP
HDETYCDPYSFIRYYMNVRASWLKDQNKNSFVGWSTDWSPYAD RVQPTISIVRFPNITNLCPFGEVFNASKFASVYAW
NRKRISFERDISTEIYQAGSTPCNGQVGLNCYYPLERYGFHPTTGVNYQPFRVVVLSFELLNGPATVCGTRTLYQFQFQ
EALCQAAKHEGPLHKNCVADYSVLYNSTSFSTFKCYGVSPTKLNDLCFTNVYADSFVVKGDEVRQIAPGQTGVIADYNY
KLPDDFTGCVIAWNSVKQDALTGGNYGYLYRLFRKSKPLLNYFEPLFTLKPCDISNSTEAGQKLFNMLRLGKSEPWTLA
LENVVGAKNPLFHVSND
```

When writing a fasta file, the program use the following identifier [1]:

| Line value | Identifier [1] |
| ---------- | -------------- |
| Header     | >              |
| Comment    | ;              |
| Sequence   |                |

[1]: Identifier in this case means the first character per line, used to distinguish between what kind of content is on that line.

---

## Contributing

Contributions are welcome! Check out the [Contribution Guide](https://github.com/exTerEX/libfasta/blob/main/.github/CONTRIBUTING.md).

## License

This project is licensed under `Apache-2.0`. See [LICENSE](LICENSE) for more information.
