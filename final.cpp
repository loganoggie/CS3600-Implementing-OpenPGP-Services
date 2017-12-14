// Logan Nielsen
// CS3600 final project
// Implementing Authentication and Confidentiality Services in OpenPGP

// g++ mycxxprog.cpp -lgmpxx -lgmp

/*
# AUTHENTICATION SERVICE
 • Generation of Authenticated Message
    – Alice creates a message digest of the outgoing message m, denoted by h(m).
    – Using RSA, Alice signs the message digest h(m) to produce a digital signature s of m, and the
        authenticated message is denoted by m||s where || denotes message concatenation.
 • Verification of Authenticated Message
    – Upon receiving m||s, Bob computes the message digest of m.
    – Bob decrypts s using Alice’s public key and performs the rest of verification steps.

# CONFIDENTIALITY SERVICE
 • Message Encryption
    – Alice randomly generates a session key k s and encrypts her message m with the session key. The encrypted
        message is denoted by E k s (m) where E is a symmetric key encryption scheme, such as AES.
    – Alice encrypts k s using Bob’s public key (n, e) b . The encrypted key denoted by E (n,e) b (k s ) where E is the
        RSA encryption function.
    – Alice sends E k s (m)||E (n,e) b (k s ) to Bob
 • Message Decryption
    – Upon receiving E k s (m)||E (n,e) b (k s ), Bob decrypts the encrypted key with his private key to obtain k s .
    – Using k s , Bob decrypts the encrypted message to get m.

# IMPLEMENTATION REQUIREMENTS
 • Programming language: C/C++ with GMP and OpenSSL libraries
 • RSA: Use your own implementation from the previous project or OpenSSL
 • AES: Use the appropriate functions from OpenSSL, with AES-128
 • Message digest: You can adopt the “dgst” function in OpenSSL, with SHA-512

# MESSAGE FORMATS
 • Plaintext message: a string of characters saved in the first line of a file. An example file is provided; all should be
    UTF-8 Unix delimited.
 • Authenticated message: the plaintext message is stored on the first line, and the signature is stored on the second
    line of a file.
 • Encrypted message: the encrypted message is stored on the first line, and the encrypted session key is stored on
    the second line of a file.

# DELIVERABLES
 • README: describe the purpose of your files and provide instructions on how to compile and execute your program.
 • Well-documented source code.

*/

#include <iostream>
#include <fstream>
#include <gmpxx.h>
using namespace std;


int main()
{
    ofstream out;
    ifstream in;
    string inf_alice_keypair, inf_bob_keypair, inf_alice_plaintext_message;
    string outf_alice_auth_message, outf_verify_bobs_steps, outf_alice_encryption, outf_bob_decryption;

    cout << "1. Enter the name of the file that contains Alice’s public-private key pair: " << endl;
    cin >> inf_alice_keypair;

    cout << "2. Enter the name of the file that contains Bob’s public-private key pair: " << endl;
    cin >> inf_bob_keypair;

    cout << "3. Enter the name of the file that contains Alice’s plaintext message: " << endl;
    cin >> inf_alice_plaintext_message;

    cout << "4. Enter the output file name to store Alice’s authenticated message: " << endl;
    cin >> outf_alice_auth_message;

    cout << "5. Enter the output file name to store the verification steps performed by Bob: " << endl;
    cin >> outf_verify_bobs_steps;

    cout << "6. Enter the output file name to store Alice’s encrypted message: " << endl;
    cin >> outf_alice_encryption;

    cout << "7. Enter the output file name to store Bob’s decryption of Alice’s plaintext message: " << endl;
    cin >> outf_bob_decryption;



    mpz_t a, b, c;
    unsigned long int d = 100;
    mpz_init_set_str(a, "1024", 10);
    mpz_init_set_str(b, "1024", 10);
    mpz_init(c);

    mpz_pow_ui(c, a, d);

//    out.open("test.txt");
//    out.close();

    gmp_printf("mpz int c equals: %Zd \n", c);

    return 0;
}







// eof
