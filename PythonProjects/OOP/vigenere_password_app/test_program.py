from vigenere_cipher import VigenereCipher

#def test_encode():
#    cipher = VigenereCipher("TRAIN")
#    encoded = cipher.encode("ENCODEDINPYTHON")
#    assert encoded == "XECWQXUIVCRKHWA"

def test_encode_character():
    cipher = VigenereCipher("TRAIN")
    encoded = cipher.encode("E")
    assert encoded == "X"   

