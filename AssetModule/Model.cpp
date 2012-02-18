#include "Model.h"

#include "Vertex.h"
#include "TextureCoordinate.h"
#include "Normal.h"
#include "Face.h"

Model::Model()
{

}


void Model::addFace(Face& face)
{
	m_faces.push_back(face);
}

void Model::addVertex(Vertex& vertex)
{
	m_vertices.push_back(vertex);
}

void Model::addTextureCoordinate(TextureCoordinate& texture_coordinate)
{
	m_texture_coordinates.push_back(texture_coordinate);
}

void Model::addNormal(Normal& normal)
{
	m_normals.push_back(normal);
}

bool Model::isValid() const
{
	/* Get our index array counts */
	uint32_t vertices_length = m_vertices.size();
	uint32_t texture_coordinates_length = m_texture_coordinates.size();
	uint32_t normals_length = m_normals.size();

	/* if a count is zero, let's make it equal to the vertices length to save a comparison */
	if (texture_coordinates_length == 0)
		texture_coordinates_length = vertices_length;

	if (normals_length == 0)
		normals_length = vertices_length;


	/* Is this even a valid geometric primitive? */
	if ((vertices_length != texture_coordinates_length) || (vertices_length != normals_length))
		return false; /* invalid model */
	else
		return true;
}


std::vector<Face> const& Model::getFaces() const
{
	return m_faces;
}

std::vector<Vertex> const& Model::getVertices() const
{
	return m_vertices;
}

std::vector<TextureCoordinate> const& Model::getTextureCoordinates() const
{
	return m_texture_coordinates;
}

std::vector<Normal> const& Model::getNormals() const
{
	return m_normals;
}

enum GeometryType Model::getPrimitiveType() const
{
	return Invalid;
}
