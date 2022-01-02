import random
import math

def Miller_Rabin_Test(p, k = 4):
    #zero step
    s = 0
    d = p - 1
    while d % 2 == 0:
        d>>=1
        s+=1
    assert(2**s * d == p - 1)
    counter = 0
    #first step
    while counter < k:
        x = (random.randint(2, p - 1))
        if math.gcd(x, p) != 1:
            return True
        else:
            #second step
            #2.1
            if pow(x, d, p) == 1 or pow(x, d, p) == p - 1:
                return False
            #2.2
            else:
                for r in range(1, s - 1):
                    if pow(x, (d * 2**r), p) == p - 1:
                        return False
                    elif pow(x, (d * 2**r), p) == 1:
                        return True
                #third step
                counter = counter + 1
    return True

def generate_random_256_bit_numbers():
    while len(primary_values) != 4:
        prime_number_was_NOT_found = True
        while prime_number_was_NOT_found:
            random_number = random.getrandbits(256)
            trial_division = True
            while (trial_division):
                if random_number % 2 == 0 or random_number % 3 == 0 or random_number % 5 == 0 or random_number % 7 == 0:
                    #print("Nope: ", random_number)
                    random_number = random.getrandbits(256)
                else:
                    trial_division = False
            #print("May be yeah: ", random_number)
            prime_number_was_NOT_found = Miller_Rabin_Test(random_number)
        #print("Definately yeah: ", random_number)
        primary_values.append(random_number)

def euclid_algorithm(a, b):
    if b == 0:  
        return a, 1, 0
    else:
        d, x, y = euclid_algorithm(b, a % b)
        return d, y, x - y * (a // b)
    
def inverted_element_by_mod(number, module):
    return euclid_algorithm(number, module)[1] % module

def generate_keys(p, q):
    n = p * q
    f_n_ = (p - 1) * (q - 1)
    print("f: ", f_n_)
    e = random.randint(2, f_n_ - 1)
    while math.gcd(e, f_n_) != 1:
        e = random.randint(2, f_n_ - 1)
    d = inverted_element_by_mod(e, f_n_)
    return n, e, d

primary_values = []
A_open_keys = []
A_secret_keys = []
B_open_keys = []
B_secret_keys = []

generate_random_256_bit_numbers()

while primary_values[0]*primary_values[1] <= primary_values[2]*primary_values[3]:
    primary_values.clear()
    generate_random_256_bit_numbers()

print("Secret keys: ", primary_values)

n, e, d = generate_keys(primary_values[0], primary_values[1])
A_secret_keys.append(primary_values[0])
A_secret_keys.append(primary_values[1])
A_secret_keys.append(d)
A_open_keys.append(n)
A_open_keys.append(e)
print("A open keys: ", A_open_keys)
print("A secret keys: ", A_secret_keys)

n, e, d = generate_keys(primary_values[2], primary_values[3])
B_secret_keys.append(primary_values[2])
B_secret_keys.append(primary_values[3])
B_secret_keys.append(d)
B_open_keys.append(n)
B_open_keys.append(e)
print("B open keys: ", B_open_keys)
print("B secret keys: ", B_secret_keys)

def encrypt(M, e, n):
    return pow(M, e, n)

def decrypt(C, d, n):
    return pow(C, d, n)

def sign(M, d, n):
    return pow(M, d, n)

def verify(M, S, e, n):
    if M == pow(S, e, n):
        return True
    else:
        return False

M = random.randint(1, n - 1)
print("Open text: ", M)

C = encrypt(M, A_open_keys[1], A_open_keys[0])
print("Encrypted text: ", C)

M_decr = decrypt(C, A_secret_keys[2], A_open_keys[0])
print("Decrypted text: ", M_decr)

S = sign(M, A_secret_keys[2], A_open_keys[0])
print("Sign: ", S)

if verify(M, S, A_open_keys[1], A_open_keys[0]):
    print("Text verified!")
else:
    print("Text NOT verified!")


def send_key(k, e_1, n_1):
    S = sign(k, e_1, n_1)
    k_1 = pow(k, e_1, n_1)
    S_1 = pow(S, e_1, n_1)
    return k_1, S_1, S

def recieve_key(k_1, S_1, d_1, n_1):
    k = pow(k_1, d_1, n_1)
    S = pow(S_1, d_1, n_1)
    if k == verify_sign(S, public_exponent_d, modulus_n):
        print("Key verified!")
    else:
        print("Key NOT verified!")
    return k, S

def verify_sign(S, e, n):
    return pow(S, e, n)

modulus_n = 36689245442287712590360299666150898957640956295755131383830406860224960443454934864604168325395420056958992048118418457084728512601231621208038663848223297463
public_exponent_d = 65537

#k = random.randint(1, n - 1)
k = 2845122624493474161404692023938310902622787205999805091932486128103394559160
print("Before sending:\nmodulus = ", modulus_n, "\npublic exponent = ", public_exponent_d)
print("k: ", k)

k_1, S_1, S = send_key(k, public_exponent_d, modulus_n)
print("S: ", S)

print("After sending:\nk_1: ", k_1)
print("S_1: ", S_1)
k_recieved, S_recieved = recieve_key(k_1, S_1, public_exponent_d, modulus_n)

print("After recieving:\nk: ", k)
print("Recieved S: ", S)