import random

import pygame

# Inicialize o Pygame
pygame.init()

# Crie a janela
largura_janela = 900
altura_janela = 400
janela = pygame.display.set_mode((largura_janela, altura_janela))

pygame.display.set_caption('IsabelaBoluda')

# Carregue e redimensione as imagens

# Peixe
imagem = pygame.image.load(r'assets/peixe.jpeg')

# Pontos
#imagem = pygame.image.load(r'assets/oi.png')

imagem = pygame.transform.scale(imagem, (50, 50))

# Crie uma lista para armazenar as informações de cada imagem
imagens = []
for i in range(40):
  imagens.append({
      'x': random.randrange(largura_janela - imagem.get_width()),
      'y': random.randrange(altura_janela - imagem.get_height()),
      'velocidade_x': 2,
      'velocidade_y': 2,
  })

# Game loop
rodando = True
while rodando:
  for evento in pygame.event.get():
    if evento.type == pygame.QUIT:
      rodando = False

  # Atualize a posição de cada imagem e verifique se atingiu a borda da janela
  for img in imagens:
    img['x'] += img['velocidade_x']
    img['y'] += img['velocidade_y']
    if img['x'] < 0 or img['x'] + imagem.get_width() > largura_janela:
      img['velocidade_x'] *= -1
    if img['y'] < 0 or img['y'] + imagem.get_height() > altura_janela:
      img['velocidade_y'] *= -1

  # Verifique se as imagens colidiram. Se sim, inverta a direção.
  for i in range(len(imagens)):
    for j in range(i + 1, len(imagens)):
      if (imagens[i]['x'] < imagens[j]['x'] + imagem.get_width()
          and imagens[i]['x'] + imagem.get_width() > imagens[j]['x']
          and imagens[i]['y'] < imagens[j]['y'] + imagem.get_height()
          and imagens[i]['y'] + imagem.get_height() > imagens[j]['y']):
        imagens[i]['velocidade_x'], imagens[j]['velocidade_x'] = imagens[j][
            'velocidade_x'], imagens[i]['velocidade_x']
        imagens[i]['velocidade_y'], imagens[j]['velocidade_y'] = imagens[j][
            'velocidade_y'], imagens[i]['velocidade_y']

  # Desenhe cada imagem na nova posição
  janela.fill((255, 255, 255))  # Preencha a janela com branco
  for img in imagens:
    janela.blit(imagem, (img['x'], img['y']))

  # Atualize a janela
  pygame.display.flip()

pygame.quit()
