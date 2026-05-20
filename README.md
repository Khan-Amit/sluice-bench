# sluice-bench – Benchmark filter for remote testing

Compile with:

    make

Run with:

    cat data.txt | ./sluice_bench > filtered.txt

The filter reads lines from stdin, applies `is_ripe()` rules, and writes accepted lines to stdout. Statistics are printed to stderr.

## Example

    echo "short" | ./sluice_bench
    # rejected (line too short)

    echo "this is a long line" | ./sluice_bench
    # accepted

## Modify the filter

Edit `is_ripe()` in `sluice_bench.c` to change the acceptance rules.

## License

MIT (see LICENSE file)
