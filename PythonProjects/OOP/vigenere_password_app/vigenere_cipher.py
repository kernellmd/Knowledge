class VigenereCipher:
    def __init__(self, keyword):
        self.keyword = keyword

    def encode(self, plaintext):
        plaintext = plaintext.replace(" ", "").upper()
        cipher = []
        keyword = self.extend_keyword(len(plaintext))
        for p,k in zip(plaintext, keyword):
            cipher.append(combine_character(p, k))
        return "".join(cipher)

    def decode(self, ciphertext):
        plain = []
        keyword = self.extend_keyword(len(ciphertext))
        for p,k in zip(ciphertext, keyword):
            plain.append(separate_character(p, k))
        return "".join(plain)

    def extend_keyword(self, number):
        repeats = number // len(self.keyword) + 1
        return (self.keyword * repeats)[:number]

def combine_character(plain, keyword):
    plain = plain.upper()
    keyword = keyword.upper()
    plain_num = ord(plain) - ord("A")
    keyword_num = ord(keyword) - ord("A")
    return chr(ord("A") + (plain_num +keyword_num) % 26)

def separate_character(cipher, keyword):
    cipher = cipher.upper()
    keyword = keyword.upper()
    cipher_num = ord(cipher) - ord("A")
    keyword_num = ord(keyword) - ord("A")
    return chr(ord("A") + (cipher_num - keyword_num) % 26)
    
