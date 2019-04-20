#include <Alembic/AbcGeom/All.h>
#include <Alembic/AbcCoreOgawa/All.h>

using namespace Alembic::Abc;
using namespace Alembic::AbcGeom;

int main()
{
    constexpr size_t num_verts = 8;
    constexpr float verts_1[] =
    {
        - 1.0f, - 1.0f, - 1.0f,
        + 1.0f, - 1.0f, - 1.0f,
        - 1.0f, + 1.0f, - 1.0f,
        + 1.0f, + 1.0f, - 1.0f,
        - 1.0f, - 1.0f, + 1.0f,
        + 1.0f, - 1.0f, + 1.0f,
        - 1.0f, + 1.0f, + 1.0f,
        + 1.0f, + 1.0f, + 1.0f,
    };
    constexpr float verts_2[] =
    {
        - 2.0f, - 1.0f, - 1.0f,
        + 1.0f, - 1.0f, - 1.0f,
        - 1.0f, + 1.0f, - 1.0f,
        + 1.0f, + 1.0f, - 1.0f,
        - 1.0f, - 1.0f, + 1.0f,
        + 1.0f, - 1.0f, + 1.0f,
        - 1.0f, + 1.0f, + 1.0f,
        + 2.0f, + 1.0f, + 1.0f,
    };
    constexpr float verts_3[] =
    {
        - 2.0f, - 1.0f, - 1.0f,
        + 1.0f, - 1.0f, - 2.0f,
        - 1.0f, + 1.0f, - 1.0f,
        + 1.0f, + 1.0f, - 1.0f,
        - 1.0f, - 1.0f, + 1.0f,
        + 1.0f, - 1.0f, + 1.0f,
        - 1.0f, + 1.0f, + 2.0f,
        + 2.0f, + 1.0f, + 1.0f,
    };
    constexpr size_t num_indices = 24;
    constexpr int indices[] =
    {
        0, 4, 6, 2,
        5, 1, 3, 7,
        0, 1, 5, 4,
        6, 7, 3, 2,
        1, 0, 2, 3,
        4, 5, 7, 6,
    };
    constexpr size_t num_counts = 6;
    constexpr int counts[] = { 4, 4, 4, 4, 4, 4 };

    OArchive archive(Alembic::AbcCoreOgawa::WriteArchive(), "test.abc");

    OPolyMesh mesh_obj(OObject(archive, kTop), "mesh");
    OPolyMeshSchema& mesh = mesh_obj.getSchema();

    const OPolyMeshSchema::Sample mesh_samp_1(V3fArraySample((const V3f*) verts_1, num_verts),
                                              Int32ArraySample(indices, num_indices),
                                              Int32ArraySample(counts, num_counts));
    const OPolyMeshSchema::Sample mesh_samp_2(V3fArraySample((const V3f*) verts_2, num_verts));
    const OPolyMeshSchema::Sample mesh_samp_3(V3fArraySample((const V3f*) verts_3, num_verts));

    mesh.set(mesh_samp_1);
    mesh.set(mesh_samp_2);
    mesh.set(mesh_samp_3);

    return 0;
}
