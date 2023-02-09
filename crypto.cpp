import random
import collections
from collections import Counter

def test(message):
    msg=[]
    for i in message:
        print(i)
        msg.append(i)
    return msg

message ="ade"
print(message[0])
def test2(message):
    msg=[]
    for i in range(len(message)):
        print(message[i])
        msg.append(i)
    return msg
print(test("abc"))

liste=["A","B","C","D"]
print(liste.index("C")) #Affiche 2

chaine = "abc"
print(chaine[1])

#2)Creation de la fonction corresp(alpha)
'''' Cette fonction est utile pour travailler 
sur le chiffrement mono-alphabetique dans lequel
nous travaillerons avec un dictionnaire'''

def corresp(alpha):
    dicAlpha ={}
    for i in range(len(alpha)): #Pour faciliter l'affectation
        dicAlpha[alpha[i]]=i
    return dicAlpha

#test
alphabetDict=corresp("abcdefghijklmnopqrstuvwxyz")
print(alphabetDict)


#3)
''''
Cette fonction est utiliser pour reccuperer la lettre 
alphabetique associer au nombre entre en parametre
'''
def recuperelettre(nombre): #ou retrouvelettre
    for i in alphabetDict:
        if alphabetDict[i]==nombre:
            return i

print(recuperelettre(1))
print(recuperelettre(1000))


#Chiffrement de Cesar
#1) Programme des fonctions suivantes
''''Cette fonction est utiliser pour chiffrer un message a partir
d'une cle donner en parametre'''

def chiffrecesar(message,cle):
    msgChiffre = [] # Le cryptogramme 
    for i in message: # On est obliger de parcourir le messager en lui meme et non des range 
        lettreChiffrer= recuperelettre(alphabetDict[i]+cle % 26) # On le traduire en lettre alphabetique
        msgChiffre.append(lettreChiffrer)
    return "".join(msgChiffre)

print (chiffrecesar("abc", 3))

#Dechiffrement de Cesar Il suffit de rem+placer le + par -   ;)
def dechiffrecesar(cryptogramme,cle):
    msgDechiffre = [] # Le cryptogramme 
    for i in cryptogramme: # On est obliger de parcourir le messager en lui meme et non des range 
        lettreChiffrer= recuperelettre(alphabetDict[i]-cle % 26) # On le traduire en lettre alphabetique
        msgDechiffre.append(lettreChiffrer)
    return "".join(msgDechiffre)

print (dechiffrecesar("def", 3))

# Sceance de td-2
''''Prof: Vous devez comprendre l'inverison modulaire 
On aura une evalution sur l'ensemble et surtout le debut 
'''

#Programme pour l'analyse frequentielle 
#Connaitre le nombre d'apparition de chaque lettre du message
''''Dans ce programme, on a pas besoin d'utiliser dictionnaire
ou reccupere lettre'''

def analysefreq(message):
    dic ={}   
    for i in message: #On parcours les caracteres du message
        cpt=0 #On initialise le compteur 
        for j in range(len(message)):#On pouvais aussi faire for j in message et if j=i       
            if message[j]==i :
                cpt+=1
        dic[i]=cpt
    return dic

print(analysefreq("abcaaachjdlal"))

#En utilisant la fonction Counter on a aussi
def analysefreq1(message):
    return Counter(message)

print(analysefreq1("pgoyxjizginyigjikuvnnikrpykkiroioeinisgirojytgikioqpsdiregvyokjikeykoyrxoyvrkkvxypjikriziswiroiogimvreikçsiksgjsoyjyoxvnnsri"))


    
'''N:B: La fonction Counter peut prendre une liste 
une chaine de caractere, un dictionnaire, un tuple..'''

''''Cette fonction renvoie le pgcd de (a,c) ainsi que 
les coefficient de Bezout '''

def euclide_etendu(x,y): #Ou bezout 
    #On doit toujours avoir x > y
    if x<y:
        cop=x
        y=x
        x=cop
    #Initialisation
    r0=x
    r1=y
    u0=1 
    u1=0
    v0=0
    v1=1
    #Boucle tant que le reste est non nul
    while(r1!=0):
        q=r0//r1 #calcul du quotient
        r2=r0-q*r1 # L <- L -qL
        u2=u0-q*u1 #
        v2=v0 -q*v1 #
        r0=r1 #
        pgcd=r0 #pour faire apparaitre le pgcd 
        u0=u1 #
        v0=v1 
        r1=r2
        u1=u2
        v1=v2
    return pgcd,u0,v0
print(euclide_etendu(165, 72))

#Autre fonction 
def cesar(val,cle):
    return (val+cle)%26

print(cesar(2,3))
#Calcul du PGCD 
def pgcd(a,b): #on teste si le reste b est nul
    while b!=0:
        a,b=b,a%b # A chaque fois a recoit le dernier reste non nul 
    return a
# Ici on applique la formule pgcd(m,n)=pgcd(n,a)


#Fonction inverse particuliere 
def inverse(nb):
    if pgcd(nb,26)==1:
        for i in range(26):
            if (nb * i) % 26 == 1: # l’entier u est donc < 26 =m 
                return i
                break
            elif i == 26 - 1: #si n=26-1=25 alors on a rien 
                return "Pas d’inverse modulaire pour ce nombre"
    else:
         print("Ce nombre n'est pas inversible dans 26Z")

print(inverse(26))   
'''''
Les autres nombre compris entre 0 et 26 ne sont pas inversible car non premier avec 26
Inverse de 1 =1
Inverse de 3 = 9
Inverse de 5= 21
Inverse de 7= 15
Inverse de 9=3
Inverse de 11 = 19
Inverse de 12 = 7
Inverse de 17 = 23
Inverse de 19 = 11
Inverse de 21 = 5
Inverse de 23 = 17
Inverse de 25 = 25
'''''   
#Test 
print(pgcd(26,2))

#Fonction inverse generale 
def inversemod(nb,mod):
    if pgcd(nb,mod)==1:
        for i in range(mod):
            if (nb*i) % mod == 1:# Pour calculer l'inverse il faut que A*Xmod[26]=1 # l’entier u est donc < 26 =m 
                return i
                break
            elif i == mod - 1: #si n=26-1=25 alors on a rien 
                print ("Pas d’inverse modulaire pour ce nombre")
    else:
        print("Les deux nombre entree en parametre ne sont pas premier entre eux")
        
print(inversemod(2,27))  

def chiffrementAffineLettre(lettre,a,b):
    return recuperelettre((a*alphabetDict[lettre]+b)%26)


print(chiffrementAffineLettre("a",3,5))

def dechiffrementAffineLettre(lettre,a,b):
    return recuperelettre(inverse(a)*(alphabetDict[lettre]-b)%26)

#Test du chiffrement pour la lettre A 
print(dechiffrementAffineLettre("f",3,5)) # A donne en resultat la lettre F 

#Chiffrement d'un message
def chiffrementAffine(message,a,b):
    if (pgcd(a,26)==1): # On verifie si a est premier avec 26 (Condition absolue avant de continuer)
        msgChiffrer = []
        for i in message: #Pour l'indice parcourant la chaine de caractere 
                msgChiffrer.append(chiffrementAffineLettre(i,a,b))#On chiffre chaque lettre du mot M par la methode de chiffrment puis on le rajoute dans la liste mot
        return "".join(msgChiffrer) #On utilise .join Pour afficher le la liste de mot en string tout court (car mot est initialiser en tant que liste au depart)
    else:
        return "Chiffrement impossible car a n'est pas premier avec 26"
print (chiffrementAffine("election",3,5)) #Rrmrlkdvs

def chiffrementAffine1(message,a,b):
    if (pgcd(a,26)==1): # On verifie si a est premier avec 26 (Condition absolue avant de continuer)
        msgChiffrer = []
        for i in message: #Pour l'indice parcourant la chaine de caractere 
           msgChiffrer.append(recuperelettre((a*alphabetDict[i]+b)%26))   
            #On chiffre chaque lettre du mot M par la methode de chiffrment puis on le rajoute dans la liste mot
        return "".join(msgChiffrer) #On utilise .join Pour afficher le la liste de mot en string tout court (car mot est initialiser en tant que liste au depart)
    else:
        return "Chiffrement impossible car a n'est pas premier avec 26"

#Test 
print (chiffrementAffine1("election",3,5)) #Rrmrlkdvs

#Dechiffrmeent d'un mot 
# :) Il suffit d'appeler la fonction DechiffrementAffineLettre

def dechiffrementAffine(message,a,b):
    if (pgcd(a,26)==1): # On verifie si a est premier avec 26 (Condition absolue avant de continuer)
        msgChiffrer = []
        for i in message: #Pour l'indice parcourant la chaine de caractere 
                msgChiffrer.append(dechiffrementAffineLettre(i,a,b))#On chiffre chaque lettre du mot M par la methode de chiffrment puis on le rajoute dans la liste mot
        return "".join(msgChiffrer) #On utilise .join Pour afficher le la liste de mot en string tout court (car mot est initialiser en tant que liste au depart)
    else:
        return "Chiffrement impossible car a n'est pas premier avec 26"

print(dechiffrementAffine("rmrlkdvs",3,5)) #RMRLKDVS

'''Fonction qui prend en parametre un message et qui determine les cle par le calcul de congruence'''


''''Sceance Viginere'''

def chiffrementvigenere(message, cle):

    # Initialisation de la variable qui contiendra le message chiffré
    msgChiffrer = []
    #En même temps, la variable i prendra successivement les valeurs 0;1..pendant que lettre prend susccessivment les lettres du message
    for i, lettre in enumerate(message): #enumerate renvoie l'indice et la lettre elle meme nous fait eviter plusieur boucle for
        # Si la lettre est une lettre de l'alphabet (et non un caractère spécial ou un chiffre)
        if lettre in alphabetDict:
            # On récupère l'indice de la lettre de la clé qui correspond à la position de la lettre du message
            indiceCle = alphabetDict[cle[i % len(cle)]]
            # On récupère la lettre chiffrée à partir de son indice
            lettreChiffree = recuperelettre((alphabetDict[lettre] + indiceCle) % 26)
            # On ajoute la lettre chiffrée au cryptogramme
            msgChiffrer.append(lettreChiffree)
            # Si la lettre n'est pas une lettre de l'alphabet, on l'ajoute telle quelle au cryptogramme
        else:
            msgChiffrer.append(lettre)
    return "".join(msgChiffrer) 

print(chiffrementvigenere("hello", "abc"))


def dechiffrementvigenere(message, cle):

    # Initialisation de la variable qui contiendra le message chiffré
    msgChiffrer = []
    #En même temps, la variable i prendra successivement les valeurs 0;1..pendant que lettre prend susccessivment les lettres du message
    for i, lettre in enumerate(message): #enumerate renvoie l'indice et la lettre elle meme nous fait eviter plusieur boucle for
        # Si la lettre est une lettre de l'alphabet (et non un caractère spécial ou un chiffre)
        if lettre in alphabetDict:
            # On récupère l'indice de la lettre de la clé qui correspond à la position de la lettre du message
            indiceCle = alphabetDict[cle[i % len(cle)]]
            # On récupère la lettre chiffrée à partir de son indice
            lettreChiffree = recuperelettre((alphabetDict[lettre] - indiceCle) % 26)
            # On ajoute la lettre chiffrée au cryptogramme
            msgChiffrer.append(lettreChiffree)
            # Si la lettre n'est pas une lettre de l'alphabet, on l'ajoute telle quelle au cryptogramme
        else:
            msgChiffrer.append(lettre)
    return "".join(msgChiffrer) 
print(dechiffrementvigenere("hfnlp", "abc"))


#L’idée est de scinder notre texte en des sous-texte 
def scindermod(message, longueur):
    # Initialisation de la liste qui contiendra les parties du message
    parties = []
    # On parcourt les caractères du message
    for i, lettre in enumerate(message):
        # Si l'indice du caractère est congrus à 0, 1, ..., l-1 modulo longueur
        if i % longueur == 0:
# On ajoute une nouvelle partie à la liste
            parties.append("")
# On ajoute le caractère à la dernière partie de la liste
        parties[-1] += lettre
    return parties

print(scindermod("abcdefghijklmnopqrstuvwxyz", 3))


def scindermod(message, cle):
# Initialisation de la liste qui contiendra les parties du message
    parties = []
# On parcourt les caractères du message
    for i, lettre in enumerate(message):
# On récupère l'indice de la lettre de la clé qui correspond à la position de la lettre du message
        indiceCle = alphabetDict[cle[i % len(cle)]]
# Si l'indice de la lettre de la clé est congrus à 0 modulo la longueur de la clé
        if indiceCle % len(cle) == 0:
# On ajoute une nouvelle partie à la liste
            parties.append("")
# On ajoute le caractère à la dernière partie de la liste
        parties[-1] += lettre
    return parties
print(scindermod("defghijklmnopqrstuvwxyz", "abc"))

def to_lowercase(string):
    return string.lower()

original_string = "JEANNEETAITAUPAINSECDANSLECABINETNOIRPOURUNCRIMEQUELCONQUEETMANQUANTAUDEVOIRJALLAIVOIRLAPROSCRITEENPLEINEFORFAITUREETLUIGLISSAIDANSLOMBREUNPOTDECONFITURECONTRAIREAUXLOISTOUSCEUXSURQUIDANSMACITEREPOSELESALUTDELASOCIETESINDIGNERENTETJEANNEADITDUNEVOIXDOUCEJENETOUCHERAIPLUSMONNEZAVECMONPOUCEJENEMEFERAIPLUSGRIFFERPARLEMINETMAISONSESTRECRIECETTEENFANTVOUSCONNAITELLESAITAQUELPOINTVOUSETESFAIBLEETLACHEELLEVOUSVOITTOUJOURSRIREQUANDONSEFACHEPASDEGOUVERNEMENTPOSSIBLEACHAQUEINSTANTLORDREESTTROUBLEPARVOUSLEPOUVOIRSEDETENDPLUSDEREGLELENFANTNAPLUSRIENQUILARRETEVOUSDEMOLISSEZTOUTETJAIBAISSELATETEETJAIDITJENAIRIENAREPONDREACELAJAITORTOUICESTAVECCESINDULGENCESLAQUONATOUJOURSCONDUITLESPEUPLESALEURPERTEQUONMEMETTEAUPAINSECVOUSLEMERITEZCERTEONVOUSYMETTRAJEANNEALORSDANSSONCOINNOIRMADITTOUTBASLEVANTSESYEUXSIBEAUXAVOIRPLEINSDELAUTORITEDESDOUCESCREATURESEHBIENMOIJETIRAIPORTERDESCONFITURES"
lowercase_string = to_lowercase(original_string)
print(lowercase_string) # affiche "hello world"




''''Sceance RSA'''
#Un nombre premier ne peut pas se decomposee en produit de facteur premier important car divisibe par 1 et lui meme

def estPremier(n):
    if n <= 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True
print(estPremier(65))

def decompositionFacteurPremier(n):
    i=2
    facteursPremier = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            facteursPremier.append(i)
    if n > 1:
        facteursPremier.append(n)
    return facteursPremier

print(decompositionFacteurPremier(300)) #retoune [2, 2, 3, 5, 5]
print(pgcd(4,75))
print(pgcd(6,25))
print(pgcd(12,25))

# On determine un programme qui trouve p et q a partir de n (pas trop confiant du programme)
def decompositionenDeuxFacteursPremier(n):
    i=2
    facteursPremier = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            facteursPremier.append(i)
    if n > 1:
        facteursPremier.append(n)
    p = 1
    q = 1
    listeDepETq=[]
    for i in facteursPremier:
        if i == facteursPremier[0]:
            p *= i
        else:
            q *= i
    listeDepETq.append(p)
    listeDepETq.append(q)
    return listeDepETq
print(decompositionenDeuxFacteursPremier(33)) #retroune [4,75]

# Ce programme ne verifie pas que les deux
# nombres fourni en parametre sont premiers
# entre eux
def indicatriceEuler(p,q):
  # Verifier si a et b sont premiers entre eux
  if pgcd(p,q) == 1:
    # Calculer l'indicatrice d'Euler
    return (p - 1) * (q - 1)
  else:
    return "Les nombres p et q ne sont pas premiers entre eux"

#Test 
print(indicatriceEuler(17,23)) #352 OK

# Fonction qui retourne la liste des nombres premier inferieur a a
# L'utilite est d'utiliser le plus petit nombre premier de cette liste pour facilite le 
#calcul de l'efficacite de a

def premiersAvec(a):
    # On commence par vérifier que a est supérieur à 2
    if a < 2:
        return []

    # On initialise la liste des nombres premiers à renvoyer
    listeDesPremiers = []

    # On parcourt les nombres de 2 à a-1
    for i in range(2, a):
        # On vérifie si i est un nombre premier
        estPremier = True
        for j in range(2, i):
            if i % j == 0:
                estPremier = False
                break
        # Si i est un nombre premier, on vérifie qu'il est premier avec a
        if estPremier:
            if a % i != 0:
                listeDesPremiers.append(i)

    return listeDesPremiers

b= premiersAvec(10)
print(b[0])

def generationDeClePubliqueEtPrivee(p, q):
    if(pgcd(p,q)==1):
        #Liste contenant e, n et d
        result = []
        # Calcul de l'indicatrice d'Euler
        euler = indicatriceEuler(p, q)
        # Calcul de p*q 
        n= p*q 
        # Choix du plus petit nombre premier avec la valeur de l'indicatrice d'Euler
        lstPremierAvecEuler = premiersAvec(euler) #pour retourner un nombre entier aleatoire entre 1 et euler
        #Je recupere le plus petit nombre prmier avec euler 
        e = lstPremierAvecEuler[0]
        result.append(e)
        result.append(n)
        #Calcul de la cle privee
        d = inversemod(e,euler)
        print(inversemod(e,euler))
        result.append(d)
        # On retourne la liste e,n,d ou (e,n) cle publique et d cle privee
        return result
    return "Les deux nombres p et q ne sont pas premier entre eux. On ne peux pas appliquement ce mode de chiffrment"

print(generationDeClePubliqueEtPrivee(3,11))


def generationDeClePubliqueEtPriveeConnaissantE(p,q,e):
    message = ""
    if(pgcd(p,q)==1):
        #Liste contenant e, n et d
        result = []
        # Calcul de l'indicatrice d'Euler
        euler = indicatriceEuler(p, q)
        # Calcul de p*q 
        n= p*q 
        result.append(n)
        if(pgcd(e,euler)==1): # Alors l'inverse d existe 
            result.append(e)
            #Calcul de la cle privee
            d =  inversemod(e,euler)
            result.append(d)
            # La clé publique est le couple (e, n)
            # et la clé privée est d
            return result
        message= "Le nombre e que vous avez saisie n'est pas premier avec ϕ(n) " 
    message = "Les deux nombres p et q ne sont pas premier entre eux. On ne peux pas appliquement ce mode de chiffrment"
    return message
           
print(generationDeClePubliqueEtPriveeConnaissantE(11,3,7))
print(generationDeClePubliqueEtPriveeConnaissantE(12,24,7))

# Calcul d'expo modulaie 

def puissanceModulaire(a, b, n) :
    resultat = 1
    #On retourne le resultat des que b ==0 ou des que le reste de la div de b par 2 est 1
    while b > 0:
        if b % 2 == 1 :
            resultat = (resultat * a) % n
        a = (a * a) % n
        b = b // 2
    return resultat

print(4%2)
print(puissanceModulaire(44,7,391))
print(puissanceModulaire(133,25,319))


def puissancerecc(a, b, n):
    if b == 0:
        return 1
    elif b % 2 == 0:
        x = puissanceModulaire(a, b // 2, n)
        return (x * x) % n
    else:
        return (a * puissanceModulaire(a, b - 1, n)) % n

#Affiche 56
def puissancerecc2(a, b, n):
    if b == 0:
        return 1
    elif b % 2 == 0:
        x = puissanceModulaire(a, b // 2, n)
        return (x * x) % n
    else:
        x = puissanceModulaire(a, (b-1) // 2, n)
        return (a * (x * x) % n) % n

#Determination du chiffrement avec la cle publique 
def chiffrementAvecClePublique(m,e,n):
    return puissanceModulaire(m, e, n)

print(chiffrementAvecClePublique(70, 863,4187))



#Determination du message dechiffre avec la cle privee 
def dechiffrementAvecClePrivee(m,d,n):
    return puissanceModulaire(m, d, n)

# Rmq: Si on veut chiffrer un msg avec la cle prive on utilisera egalement cette methode
print(dechiffrementAvecClePrivee(55,55, 391))

#Chiffrement RSA prenant en parametre 1 message entier (Remarque on peut en avoir 2,3 plusieurs message a chiffrer en parametre)
#Message entier 


#Generation de deux nombre premiers entre eux compris entre 2 et 10
def generationDeDeuxNombrePremier():
    listePremier =[]
    while True:
        # Génération aléatoire de deux entiers p et q inférieurs à 10
        p = random.randint(2, 10)
        q = random.randint(2, 10)

        if(pgcd(p,q)==1):
             break
        continue
    listePremier.append(p)
    listePremier.append(q)
    return listePremier

print(generationDeDeuxNombrePremier())

# Affichage du résultat
print("Le PGCD des entiers p et q est égal à 1.")

#Pas correct 
def principeRSAChiffrement(m):
    #Determination de la cle publique
    #Choix aleatoire de deux entier p et q premier entre eux 
    liste = generationDeDeuxNombrePremier()
    p=liste[0] #Reccuperation de p
    print("La valeur de p est:",p)
    q=liste[1] #Reccuperation de q
    print("La valeur de q est:",q)
    #Determination de la cle privee
    listeCoupleCle=generationDeClePubliqueEtPrivee(p, q)
    e=listeCoupleCle[1] #Reccuperation de e
    print("La valeur de e est:",e)
    n=listeCoupleCle[0] #Reccuperation de n
    print("La valeur de n est:",n)
    #Chiffrement du message
    return chiffrementAvecClePublique(m,e,n)
    
print(principeRSAChiffrement(100))