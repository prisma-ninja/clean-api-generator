import sys
import os
import shutil
import argparse
import re

def to_tiret_case(text):
  nouvelle_chaine = text.replace("_", "-")
  return nouvelle_chaine

def to_lower_camel_case(text):
  """
  Convertit une chaîne en lowerCamelCase.

  Args:
    text (str): La chaîne en UpperCamelCase à convertir.

  Returns:
    str: La chaîne convertie en lowerCamelCase.
  """
  if not text:
    return ""
  return text[0].lower() + text[1:]


def to_snake_case(text):
  """
  Convertit une chaîne en snake_case.

  Args:
    text (str): La chaîne à convertir.

  Returns:
    str: La chaîne convertie en snake_case.
  """
  import re
  str1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', text)
  return re.sub('([a-z0-9])([A-Z])', r'\1_\2', str1).lower()

def remplacer_chaine(chemin_repertoire, chaine_recherche, chaine_remplacement):
  """
  Remplace une chaîne de caractères par une autre dans tous les fichiers d'une arborescence.

  Args:
    chemin_repertoire (str): Le chemin du répertoire à parcourir.
    chaine_recherche (str): La chaîne de caractères à rechercher.
    chaine_remplacement (str): La chaîne de caractères par laquelle remplacer la chaîne de recherche.
  """
  for root, _, fichiers in os.walk(chemin_repertoire):
    for fichier in fichiers:
      chemin_fichier = os.path.join(root, fichier)
      with open(chemin_fichier, 'r') as fichier_lecture:
        contenu_fichier = fichier_lecture.read()

      contenu_remplace = re.sub(chaine_recherche, chaine_remplacement, contenu_fichier)

      if contenu_fichier != contenu_remplace:
        with open(chemin_fichier, 'w') as fichier_ecriture:
          fichier_ecriture.write(contenu_remplace)

def remplacer_noms_fichiers(chemin_repertoire, ancien_nom, nouveau_nom):
  """
  Remplace une chaîne de caractères par une autre dans les noms de fichiers d'une arborescence.

  Args:
    chemin_repertoire (str): Le chemin du répertoire à parcourir.
    ancien_nom (str): La chaîne de caractères à rechercher dans les noms de fichiers.
    nouveau_nom (str): La chaîne de caractères par laquelle remplacer la chaîne de recherche.
  """
  for root, _, fichiers in os.walk(chemin_repertoire):
    for fichier in fichiers:
      nom_fichier, extension = os.path.splitext(fichier)
      nouveau_nom_fichier = re.sub(ancien_nom, nouveau_nom, nom_fichier)

      if nom_fichier != nouveau_nom_fichier:
        nouveau_chemin_fichier = os.path.join(root, nouveau_nom_fichier + extension)
        os.rename(os.path.join(root, fichier), nouveau_chemin_fichier)

# todo
parser = argparse.ArgumentParser(description="Generate ...")
parser.add_argument("domain_name", help="Domaine name")
parser.add_argument("target_name", help="Target name")

# Parsing
args = parser.parse_args()

# Domain name
DomainName = args.domain_name
domain_name = to_snake_case(DomainName)
domainName = to_lower_camel_case(DomainName)

# Target name
TargetName = args.target_name
target_name = to_snake_case(TargetName)
targetName = to_lower_camel_case(TargetName)

source_dir = "template"
destination_dir = "result"

if os.path.exists(destination_dir):
  print("Le répertoire existe déjà")
  shutil.rmtree(destination_dir)
  #sys.exit(1)

shutil.copytree(source_dir, destination_dir)
shutil.move(destination_dir+"/domain_name-target_name", destination_dir+'/'+domainName+'-'+targetName)
remplacer_chaine(destination_dir, "<DOMAIN_NAME>", domain_name.upper())
remplacer_chaine(destination_dir, "<DomainName>", DomainName)
remplacer_chaine(destination_dir, "<domainName>", domainName)
remplacer_chaine(destination_dir, "<TARGET_NAME>", target_name.upper())
remplacer_chaine(destination_dir, "<TargetName>", TargetName)
remplacer_chaine(destination_dir, "<targetName>", targetName)
remplacer_noms_fichiers(destination_dir, "domain_name-target_name", to_tiret_case(domain_name)+'-'+to_tiret_case(target_name))