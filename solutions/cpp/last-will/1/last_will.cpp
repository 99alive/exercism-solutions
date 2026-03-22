// Secret knowledge of the Zhang family:
namespace zhang {
    int bank_number_part(int secret_modifier) {
        int zhang_part{8'541};
        return (zhang_part * secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() { return 512; }
    }
    namespace blue {
        int code_fragment() { return 677; }
    }
}

// Secret knowledge of the Khan family:
namespace khan {
    int bank_number_part(int secret_modifier) {
        int khan_part{4'142};
        return (khan_part * secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() { return 148; }
    }
    namespace blue {
        int code_fragment() { return 875; }
    }
}

// Secret knowledge of the Garcia family:
namespace garcia {
    int bank_number_part(int secret_modifier) {
        int garcia_part{4'023};
        return (garcia_part * secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() { return 118; }
    }
    namespace blue {
        int code_fragment() { return 923; }
    }
}

// The executor namespace that the tests call directly
namespace estate_executor {

    // Sums the bank parts from all three families
    int assemble_account_number(int secret_modifier) {
        return zhang::bank_number_part(secret_modifier) +
               khan::bank_number_part(secret_modifier) +
               garcia::bank_number_part(secret_modifier);
    }

    // Assembles the final code by multiplying the sums of fragments
    int assemble_code() {
        // Calculate the sum of all "red" fragments (Silver)
        int silver_sum = zhang::red::code_fragment() + 
                         khan::red::code_fragment() + 
                         garcia::red::code_fragment();
                         
        // Calculate the sum of all "blue" fragments (Gold)
        int gold_sum = zhang::blue::code_fragment() + 
                       khan::blue::code_fragment() + 
                       garcia::blue::code_fragment();
                   
        // The final code is the product of both sums: 778 * 2475 = 1,925,550
        return silver_sum * gold_sum;
    }

} // namespace estate_executor