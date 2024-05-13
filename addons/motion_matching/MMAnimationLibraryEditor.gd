@tool
class_name MMAnimationLibraryEditor extends Control

var library : MMAnimationLibrary

func update_info():
	pass

func _on_bake_button_pressed() -> void:
	library.bake_data()
