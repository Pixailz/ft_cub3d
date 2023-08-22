# cub3d

[PDF](https://cdn.intra.42.fr/pdf/pdf/68043/en.subject.pdf)

## TODO

## STATUS

:green_circle:	= done

:orange_circle:	= wip

:red_circle:	= not done

|Name      |done ?         | Desc                         |
|:--------:|:-------------:|:-----------------------------|
|parsing   |:green_circle: |                              |
|collision |:green_circle: |cannot pass throught wall     |
|mouse     |:green_circle: |use mouse                     |
|          |:green_circle: |move right and left           |
|          |:green_circle: |move up and down              |
|runing    |:green_circle: |can run with shift            |
|          |               |                              |
|mini map  |:green_circle: |display a minimap             |
|          |:green_circle: |- round map                   |
|          |:green_circle: |- protect outside map         |
|          |:green_circle: |- float centered by player pos|
|          |:green_circle: |- draw open/close door        |
|          |:green_circle: |- struct mini to included     |
|          |:green_circle: |- 'tab' to expand map         |
|          |:green_circle: |- 'M' to toggle map           |
|          |:green_circle: |- fov + hit                   |
|          |               |                              |
|door      |:green_circle: |door mechanism                |
|          |:green_circle: |- parse good wall in map      |
|          |:green_circle: |- display doors               |
|          |:green_circle: |- interact with door with kb  |
|          |               |                              |
|annimation|:green_circle: |animation mechanism           |
|          |:green_circle: |- parse multiple texture      |
|          |:green_circle: |- animate                     |
|          |               |                              |
|fog++     |:green_circle: |fog mechanism                 |
|          |:green_circle: |- fog on wall                 |
|          |:orange_circle:|- fov with fog                |
|          |:red_circle:   |- fov near wall buggy         |

## tips

> show diff betwen two dir, with colors
`diff --color=always -bur ./src/mandatory/ ./src/bonus | less -r`

> launch ft_helper, add -g3 disable -Werror
`make DEBUG=1`

> run mandatory maps
`make MAP=<MAP_PATH> run`

> run bonus maps
`make MAP=<MAP_PATH> run_bonus`
