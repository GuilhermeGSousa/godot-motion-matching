extends MMAnimationPlayer

var current_anim = 0

func _input(event: InputEvent) -> void:
	if event.is_action_pressed("switch_anim"):
		_next()

func _next() -> void:
	var anim_list = get_animation_list()
	print(anim_list[current_anim])
	play(anim_list[current_anim])
	seek(0.1)
	#inertialize_transition(anim_list[current_anim], 0.1)
	current_anim += 1
	if current_anim >= len(anim_list):
		current_anim = 0
