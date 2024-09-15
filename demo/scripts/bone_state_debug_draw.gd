extends Node

@export var character : MMCharacter

func _process(delta: float) -> void:
	if not character:
		return
	
	var skeleton_state = character.get_skeleton_state()
	
	for bone_state in skeleton_state:
		var pos = bone_state["position"]
		var arrow_dir = bone_state["velocity"].normalized()
		var arrow_length = 0.1
		
		DebugDraw3D.draw_sphere(pos, 0.01, Color.GREEN_YELLOW)
		DebugDraw3D.draw_arrow(pos, pos + arrow_dir * arrow_length, Color.DODGER_BLUE, 0.01)
