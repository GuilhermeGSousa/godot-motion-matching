@tool
class_name MMAnimationLibraryEditor extends Control

var player : MMAnimationPlayer

func update_info():
	pass


func _on_bake_button_pressed() -> void:
	player.bake_library_data()
