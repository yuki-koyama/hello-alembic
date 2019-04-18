#include <string>
#include <Alembic/Abc/All.h>
#include <Alembic/AbcCoreOgawa/All.h>

using Alembic::Abc::OArchive;
using Alembic::Abc::OObject;

int main()
{
    const std::string file_path = "test.abc";

    OArchive o_archive(Alembic::AbcCoreOgawa::WriteArchive(), file_path);

    return 0;
}
