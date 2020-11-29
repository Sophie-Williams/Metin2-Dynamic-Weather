///Add
#if defined(__BL_WEATHER_INFO__)
void CMapOutdoor::ChangeTextureset(const std::string& FileName)
{
	if (!FileName.compare(m_TextureSet.GetFileName()))
		return;
	
	if (!m_TextureSet.Load(FileName.c_str(), m_fTerrainTexCoordBase)) {
		TraceError("MapOutdoor::ChangeTextureset - LOAD TEXTURE SET(%s) ERROR", FileName.c_str());
		return;
	}

	CTerrain::SetTextureSet(&m_TextureSet);
}
#endif