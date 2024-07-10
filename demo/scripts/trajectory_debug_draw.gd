extends Node

@export var character : CharacterBody3D
@export var controller : MMController
@export var matcher : MotionMatcher
@export var anim_player : MMAnimationPlayer

func _physics_process(delta: float) -> void:
	DebugDraw3D.draw_position(character.transform, Color.FOREST_GREEN)
	DebugDraw3D.draw_position(controller.transform, Color.TOMATO)
	
	_draw_trajectory(controller.get_trajectory(), Color.AQUAMARINE, true)
	_draw_trajectory(controller.get_previous_trajectory(), Color.AQUA, true)

	var forward = controller.global_basis.z
	DebugDraw3D.draw_arrow(controller.global_position, controller.global_position + forward * 0.5, Color.DARK_SLATE_BLUE, .1)

	var result_data = matcher.get_last_query_result()
	
	if result_data.is_empty():
		return
	
	var library : MMAnimationLibrary = anim_player.get_animation_library(anim_player.get_animation_library_list()[0])
	
	var offset = 0
	for feature in library.features:
		var start_index = offset
		var end_index = start_index + feature.get_dimension_count()
		
		var feature_data = result_data.slice(start_index, end_index)
		
		if feature is MMTrajectoryFeature:
			_draw_trajectory(feature.get_trajectory_points(character.transform, feature_data), Color.CRIMSON, false) # feature.include_facing)

		offset += feature.get_dimension_count()
		
func _draw_trajectory(trajectory : Array[Dictionary], color : Color, include_facing : bool):
	var trajectory_points = []
	for p in trajectory:
		var pos = p["position"]
		trajectory_points.push_back(pos)
		
		if include_facing:
			var dir = Vector3.FORWARD.rotated(Vector3.UP, p["facing"])
			DebugDraw3D.draw_arrow(pos, pos - dir * 0.25, Color.ORANGE, 0.01)
	DebugDraw3D.draw_points(trajectory_points, DebugDraw3D.POINT_TYPE_SPHERE, 0.01, color)

func _input(event: InputEvent) -> void:
	if event.is_action_pressed("switch_anim"):
		controller.is_strafing = !controller.is_strafing
