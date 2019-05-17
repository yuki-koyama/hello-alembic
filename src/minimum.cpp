#include <Alembic/AbcGeom/All.h>
#include <Alembic/AbcCoreOgawa/All.h>

using namespace Alembic::Abc;
using namespace Alembic::AbcGeom;

int main()
{
    constexpr size_t num_verts = 8;
    constexpr float verts[] =
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
    constexpr size_t num_indices = 24;
    constexpr int32_t indices[] =
    {
        0, 4, 6, 2,
        5, 1, 3, 7,
        0, 1, 5, 4,
        6, 7, 3, 2,
        1, 0, 2, 3,
        4, 5, 7, 6,
    };
    constexpr size_t num_counts = 6;
    constexpr int32_t counts[] = { 4, 4, 4, 4, 4, 4 };
    constexpr float dt = 1.0f / 60.0f;

    OArchive archive(Alembic::AbcCoreOgawa::WriteArchive(), "minimum.abc");

    const TimeSampling time_sampling(dt, 0);
    const uint32_t time_sampling_index = archive.addTimeSampling(time_sampling);

    OPolyMesh mesh_obj(OObject(archive, kTop), "mesh");
    OPolyMeshSchema& mesh = mesh_obj.getSchema();

    mesh.setTimeSampling(time_sampling_index);

    const OPolyMeshSchema::Sample mesh_samp(V3fArraySample((const V3f*) verts, num_verts),
                                            Int32ArraySample(indices, num_indices),
                                            Int32ArraySample(counts, num_counts));

    mesh.set(mesh_samp);

    return 0;
}
