# Navegar o 3D Viewport

## Mover
- **Bot�o do meio do mouse (MMB)**: Manter pressionado o bot�o do meio do mouse e arrastar para rotacionar a vis�o em torno da cena. Isso permite que voc� veja os objetos de diferentes �ngulos.

## Rodar
- **Shift + MMB**: Segure a tecla Shift e, ao mesmo tempo, pressione e arraste o bot�o do meio do mouse. Isso vai mover a sua vis�o lateralmente ou verticalmente sem mudar o �ngulo da c�mera.

## Zoom
- **Roda de rolagem do mouse**: Role a roda do mouse para frente para dar zoom in (aproximar) ou para tr�s para dar zoom out (afastar).

# Transforma��es B�sicas

## Mover objetos
- **Pressione a tecla G** (de "grab") para mover o objeto livremente pelo espa�o 3D. O objeto seguir� o movimento do rato.
- Para restringir o movimento a um eixo espec�fico, pressione **X**, **Y**, ou **Z** depois de pressionar **G**. Por exemplo, **G + X** mover� o objeto apenas ao longo do eixo X.

## Rodar objetos
- **Pressione R** para entrar no modo de rota��o. O objeto ir� rodar ao redor de um ponto central.
- Assim como ao mover, voc� pode restringir a rota��o a um eixo espec�fico pressionando **X**, **Y** ou **Z** ap�s o comando **R**. Exemplo: **R + Z** rodar� o objeto ao longo do eixo Z.
- Se quiser uma rota��o precisa em um determinado grau (por exemplo, 90�), pode digitar o valor logo ap�s o atalho. Exemplo: **R + Z + 90** para rodar 90� no eixo Z.

## Escalar objetos
- **Pressione S** para entrar no modo de escala. O objeto vai aumentar ou diminuir de tamanho conforme voc� move o rato.
- Para escalar ao longo de um eixo espec�fico, use as mesmas teclas de restri��o: **S + X**, **S + Y**, ou **S + Z**. Exemplo: **S + Z** s� vai escalar o objeto verticalmente.
- Se quiser escalar o objeto proporcionalmente (em todas as dire��es ao mesmo tempo), basta usar o comando **S** sem restringir o eixo.
- Para escalar apenas ao longo de um eixo, use as teclas de restri��o, como descrito acima.

# Object Mode vs. Edit Mode

## Entender os modos de trabalho com objetos

### Modo Objeto (Object Mode)
- **O que �**: O Modo Objeto � o modo no qual voc� pode selecionar, mover, rotacionar, escalar e manipular objetos inteiros na sua cena.
- **Quando Usar**: Use o Modo Objeto quando quiser manipular um objeto completo. Aqui, voc� pode criar, deletar, duplicar e organizar v�rios objetos, como cubos, esferas, luzes e c�maras.
- **Como Acessar**: Para alternar para o Modo Objeto, pressione a tecla **Tab** (ou selecione o menu no canto superior esquerdo da janela do 3D Viewport e escolha "Object Mode").

### Modo Edi��o (Edit Mode)
- **O que �**: O Modo Edi��o permite-lhe editar a geometria interna de um objeto. Aqui, voc� pode modificar os v�rtices, arestas e faces que comp�em o objeto.
- **Quando Usar**: Use o Modo Edi��o quando quiser modificar a estrutura interna de um objeto. � ideal para fazer mudan�as detalhadas no formato, como adicionar cortes, extrus�es ou suavizar a superf�cie.
- **Como Acessar**: Para alternar para o Modo Edi��o, pressione a tecla **Tab** (ou v� ao menu e selecione "Edit Mode"). Se estiver no Modo Objeto, pressionar **Tab** muda automaticamente para o Modo Edi��o do objeto selecionado.


## Entering Edit Mode

1. Make sure you have a 3D object selected (such as a cube).
2. Look at the **left side of the screen** where you�ll see a dropdown that says **Object Mode**.
3. Click the dropdown and select **Edit Mode**.
   - Alternatively, you can press `Tab` on your keyboard to toggle between **Object Mode** and **Edit Mode**.

## Selecting Multiple Vertices

1. Once in **Edit Mode**, switch to **Vertex Select** mode by pressing `1` on your keyboard or selecting the **vertex icon** (the small dot) on the top-left corner of the 3D viewport.
2. To select multiple vertices, use one of the following methods:
   - **Box Select**: Press `B` to activate box select, then click and drag around the vertices you want to select.
   - **Lasso Select**: Hold `Ctrl` and drag the left mouse button around the vertices you want to select.
   - **Shift + Click**: Hold down `Shift` and click each vertex individually to add them to your selection.

## Entering Edit Mode

1. Make sure you have a 3D object selected (such as a cube).
2. Look at the **left side of the screen** where you�ll see a dropdown that says **Object Mode**.
3. Click the dropdown and select **Edit Mode**.
   - Alternatively, you can press `Tab` on your keyboard to toggle between **Object Mode** and **Edit Mode**.

## Selecting Multiple Vertices

1. Once in **Edit Mode**, switch to **Vertex Select** mode by pressing `1` on your keyboard or selecting the **vertex icon** (the small dot) on the top-left corner of the 3D viewport.
2. To select multiple vertices, use one of the following methods:
   - **Box Select**: Press `B` to activate box select, then click and drag around the vertices you want to select.
   - **Lasso Select**: Hold `Ctrl` and drag the left mouse button around the vertices you want to select.
   - **Shift + Click**: Hold down `Shift` and click each vertex individually to add them to your selection.

## Pull Down on the Z-Axis

With your vertices selected, follow these steps to move them downward:

1. Press `G` to initiate the "grab" (move) action.
2. Press `Z` to restrict the movement to the **Z-axis**.
3. Move your mouse downward to pull the vertices down, or type a negative number (e.g., `-1`) to move them precisely.
4. Click the left mouse button or press `Enter` to confirm the movement.

## Step 2: Duplicate the Leg

1. **Select the Leg**: Make sure the leg is selected. You should see an orange outline around it.
2. **Duplicate the Leg**:
   - Press `Shift + D` to duplicate the leg.
   - Move the duplicate to the opposite corner of the table.
   - Repeat this process to create the remaining two legs and position each one at a corner of the tabletop.


## Viewing the Table from Different Angles

To navigate your table from different perspectives, use the following **Numpad shortcuts**:

1. **Top View**: Press `Numpad 7`.
2. **Front View**: Press `Numpad 1`.
3. **Right Side View**: Press `Numpad 3`.

## Using a Reference Image in Blender

In Blender, you can use the **Add** menu to import reference images, which can aid in accurate modeling and alignment.

To access the **Add** menu in the 3D Viewport, press `Shift + A` (shortcut) or find **Add** in the top menu bar of the 3D Viewport. From the **Add** menu, go to `Image > Reference`, then select your desired image file. This will place the reference image in the scene, which you can position, rotate, and scale as needed.

You can adjust the opacity and depth of the reference image in the properties panel, making it semi-transparent or placing it in front of or behind objects 
for optimal modeling visibility. For multiple views (like front, side, and top), add each reference image from the corresponding orthographic view 
(Numpad `1`, `3`, or `7`) for easy alignment.

To prevent accidental movement, you can lock the image in the **Outliner** by selecting the lock icon next to the image entry.

## Moving a Reference Image Along the Z-Axis in Blender

### Move Along the Z-Axis

1. Press `G` (for "Grab" or Move) to activate the move tool.
2. Immediately press `Z` to constrain the movement to the Z-axis.
3. Move your mouse up or down to position the image where you want it along the Z-axis.
4. Click to confirm the position.

### Precise Positioning

- If you need exact control, look in the **Properties Panel** on the right side of the 3D Viewport (press `N` if it�s not visible).
- Under the **Item** tab, adjust the **Z Location** field to input an exact value for positioning.


## Process to create a character body in blender
- open blender in a new project with the cube
- apagar a camara e a luz
- shift para selecionar todas as images + alt + R + G (manter o alt pressionado no R e no G) para centrar no centro
- numpad 7
- alt Z para ir para xray mode
- s para fazer resclaing dentro do cubo (o cubo default tem 2 m por 2 m)
- pegar na side img e R X 90 + R Z 90 + G no x axis e meter ao lado do cubo
- pegar na front img e R X 90 e G no Y axis
- numpad 1
- pegar nas imagens e mexer para cima para que os p�s estejam 
no zero que � a bola vermelha no ecra G Z
- selecionar cubo e tab para edit mode
- fazer S para resize
- G Z e alinhar com as ancas e parte meia do torso
- (mirror) edit mode A Crl R na vertical, right click left click
- apagar os vertices de um lado
- ir as propriedades do cubo , modifiers, mirror, meter cliping check
- Crl + R e butao do meio do rato para criar divisoes
- Alinhar os vetices dos lados com os lados do peito, G X
- extrude E e criar at� a vulva divisoes, G X para alinhar
- pegar no vertice do lado da vulva, e meter na linha da anca
- pegar nos vertices da vulva e E extrude a perna
- chegar a um ponto onde o edge fica recto, S Z 0
- fazer um E at� a linha do joelho, crl R e subdiv, alinhar
- voltar acima, fazer at� a linha da axila
- fazer um grande at� cima, fazer G X para clavicula
- fazer E nos bra�os
- depois de ter a for�a basica completa
segurar alt selecionar um edge do lado,double g e mover para 
o meio, depois g para mexer para dentro

uvunrap:
- smart uv unrap � mais facil
- https://www.youtube.com/watch?v=WjS_zNQNVlw
- click a to select all
- click u , smart uv unrap



# Make a photorealistic texture without repeat:
- Assign a material (material in properties, new)
- Shader editor add a image texture
- connect with base color of principled bsdf
- shift a , input , texture cordinates
- -append the blender guru node files in helpers folder
- shift a , group, blender gurus mapping node
- in the node of guru, scale, rotate
- https://www.youtube.com/watch?v=-VgtSL5ZpYc

# Bake texture and create image texture
1. Prepare Your Cube and Materials
Ensure Your Cube Has a UV Map:

Select your cube.
Go to the UV Editing workspace.
Unwrap the cube if it doesn�t already have a UV map (U > Smart UV Project is a quick option).
Check the Material:

Confirm the image texture and mapping are correctly applied to the cube in the Shader Editor.
2. Create a New Image for Baking
Open the UV Editing or Image Editor panel.
Create a new blank image:
Click Image > New.
Name it (e.g., BakedTexture), and set the desired resolution (e.g., 1024x1024 or 2048x2048).
Leave the color as black or white.
Keep the new image active (it will be your bake target).
3. Bake the Texture
Go to the Shader Editor:

Add the new blank image texture to your material.
Connect it to the Shader Editor node tree (e.g., to the Base Color input or leave it disconnected for baking purposes).
Select this image node to make it active.
In the Render Properties panel:

Switch the Render Engine to Cycles (baking works only in Cycles).
Scroll to the Bake section.
Configure Bake Settings:

Select Diffuse or another bake type depending on what you want (e.g., combined lighting, normals, or colors).
For diffuse-only bake:
Uncheck Direct and Indirect contributions in the Bake settings if you don�t want shadows or lighting.
Ensure your cube is selected in Object Mode.
Bake:

Click Bake in the Bake section.
Wait for the process to complete.
4. Save the Baked Texture
In the Image Editor:
Save the baked texture (Image > Save As).
Choose a format like .png or .jpg depending on game engine requirements.

# baking a single texture from multiple materials
- first, on all objects, select them in object mode, ctrl + J
- divide the screen in 3 with uveditor on top left, put shader on the right screen, 3dviewpoer on bottom left
- go to object data properties, uvmaps, create a uvmap called baking
- select everything A, U, smart uv unrap (edit mode)
- create a new texture, click image, new, call it baking, 4096px right, 4096 left
- select one object, shading, create a new image texture (baking)
-  garantee all the shading image texture are selected, garantee the uvmap is select baking
- in properties go to render engine
- render engine para cycles
- abrir a bake tab
- bake type, diffuse
- contributions, tirar direct e indirect, deixar color
- ir ao render tab, meter max samples para 10, mais rapido
https://www.youtube.com/watch?v=wG6ON8wZYLc


estou nos 9:50
sz0

# --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Create a character in blender in 5 minutes (human)

## Body

## Face
- Open blender, delete all, cube, light, camera
- (add uv sphere) shift + A, mesh, UV sphere
- (sculping mode) go to the top tabs, click sculping
- (enable x simetry) right corner before scene collection, butterfly, click X
- (see better tools) left side, drag sculping tools so its 2 columns
- (put front reference image) drag image inside of blender,  
- shift para selecionar todas as images + alt + R + G (manter o alt pressionado no R e no G) para centrar no centro
- pegar na front img e R X 90 e G no Y axis
- (change properties of reference image) go to data tab, image, depht - front, opacity less
- 

- Fazer com a base mesh do sims? 



https://www.youtube.com/watch?v=BPAvvF8py1M&t=22s
estou nos 7:00

# Create a skybox in 5 minutes
- Open blender, delete light, camera
- (go to shading) go to the shading tab
- (add texture image) in shading shift + A, add texture image with skybox
- (add enviroment texture) in shading shift + A, add enviroment texture
- (go to edit mode)
- (open uv editor)
- (select all verices and rotate 270) R + 270
-


https://www.youtube.com/watch?v=4uGIeej4WFw

## Hands

## Feet

# --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# coding


# Grafics Engine Documentation, (How to)

## Load a new model into scene (old version)
- Place the model file in your project directory, preferably in the models/ folder.
- Place the texture file in the textures/ folder.

- add new model and texture variables
const std::string MODEL_PATH_2 = "models/untitled.obj";
const std::string TEXTURE_PATH_2 = "textures/a.png";

- Adjust the loadModel()

- updateUniformBuffer()

## nvidia's PhysX
- asdsadasdasdasd

## add colision to the object
- sadasdsa asd as dsa

## move the object with your hands
- asdasdasdasdas

## interact with objects
- asdsadasdasdsad

## ------------- To do
nvidia's PhysX (for the camera gravity and colition)
learn how to load more than one object into scene
do a fucntion to load a model with all the properties it needs, gravity, colition, animations, ect.
interact with objects

after writing documentation, polish the code a bit

now its all about animations, and probably a bit of ai.

Blend Multiple Animations

character ai and walking


nvidia's PhysX

ideia:
usar uma ai para fazer as paredes e ler o projecto do arquitecto

meter no motor do vulkan

usar a ai para fazer o mobiliario da casa? identificar a sala, cozinha, e dar um .exe final onde podes andar pela casa?

https://eplan.house/en/house-plans/tiny-house-plans/nwl-677034-1-3