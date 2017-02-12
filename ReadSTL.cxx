// based on:
// http://www.eng.nus.edu.sg/LCEL/RP/u21/wwwroot/stl_library.htm

#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkMassProperties.h>
 
int main ( int argc, char *argv[] )
{
  if ( argc != 2 )
    {
    cout << "Required parameters: Filename" << endl;
    return EXIT_FAILURE;
    }
 
  std::string inputFilename = argv[1];
 
  vtkSmartPointer<vtkSTLReader> reader =
    vtkSmartPointer<vtkSTLReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
 
  // Visualize
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());
 
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
  renderer->AddActor(actor);
  renderer->SetBackground(.3, .6, .3); // Background color green

#if 0
//        cleaner = vtk.vtkCleanPolyData()
//        cleaner.SetInput(self.Surface)
//      cleaner.Update()

        auto triangleFilter = vtkTriangleFilter()
        triangleFilter.SetInput(reader->GetOutputPort())
        triangleFilter.Update()
        auto massProps = vtk.vtkMassProperties()
        massProps.SetInput(triangleFilter.GetOutput())
        massProps.Update()


	std::cout << massProps.GetSurfaceArea() << "\n";

//        self.SurfaceArea = massProps.GetSurfaceArea()
//        self.Volume = massProps.GetVolume()
//        self.ShapeIndex = massProps.GetNormalizedShapeIndex()


//  std::cout << reader->getSurfaceArea() << "\n";
#endif
	reader->Update();
	vtkMassProperties* polygonProperties = vtkMassProperties::New(); 
	polygonProperties->SetInputConnection(reader->GetOutputPort());
	double area = polygonProperties->GetSurfaceArea();

	std::cout << "area= " << area << "\n";
	std::cout << "getKx="  << polygonProperties->GetKx() << "\n";
	std::cout << "getKy="  << polygonProperties->GetKy() << "\n";
	std::cout << "getKz="  << polygonProperties->GetKz() << "\n";

// temp. disable
//  renderWindow->Render();
//  renderWindowInteractor->Start();
 
  return EXIT_SUCCESS;
}
