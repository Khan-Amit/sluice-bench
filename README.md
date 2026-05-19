# sluice-bench
# sluice-bench – Benchmark filter for remote testing

Compile with `make`. Run with:

    cat data.txt | ./sluice_bench > filtered.txt

The filter rejects lines that do not match the `is_ripe()` pattern. Modify `is_ripe()` to tune for your benchmark.

## Example

    echo "short" | ./sluice_bench   # rejected
    echo "this is a long line" | ./sluice_bench   # accepted

Outputs statistics to stderr.
