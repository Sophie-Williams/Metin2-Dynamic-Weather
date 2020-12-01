#Find
		self.serverCommander=stringCommander.Analyzer()
		for serverCommandItem in serverCommandList.items():
			self.serverCommander.SAFE_RegisterCallBack(
				serverCommandItem[0], serverCommandItem[1]
			)
			
#Add above
		if app.__BL_WEATHER_INFO__:
			serverCommandList["SnowTexture"] = self.BINARY_SNOW_TEXTURE
			
#Find
	def __EnableTestServerFlag(self):
		app.EnableTestServerFlag()
		
#Add
	if app.__BL_WEATHER_INFO__:
		def BINARY_SNOW_TEXTURE(self, active):
			mode = int([1, 0][active == "disable"])
			bl_texture_list = {
				"metin2_map_a1" : ["textureset/metin2_a1.txt", "textureset/snow/snow_metin2_a1.txt"],
				"metin2_map_b1" : ["textureset/metin2_b1.txt", "textureset/snow/snow_metin2_b1.txt"],
				"metin2_map_c1" : ["textureset/metin2_c1.txt", "textureset/snow/snow_metin2_c1.txt"],
			}

			if background.GetCurrentMapName() in bl_texture_list:
				self.curtain.SAFE_FadeOut(self.SetTexture, bl_texture_list.get(background.GetCurrentMapName())[mode])			
				
		def SetTexture(self, path):
			background.ChangeTextureset(path)	
			self.curtain.FadeIn()