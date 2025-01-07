#include "AppLayer.h"

#include <EppoCore.h>
#include <EppoCore/Core/Entrypoint.h>

namespace Eppo
{
	class EppoApp : public Application
	{
	public:
		EppoApp(ApplicationSpecification specification)
			: Application(std::move(specification))
		{
			std::shared_ptr<AppLayer> layer = std::make_shared<AppLayer>();

			PushLayer(layer);
		}

		~EppoApp() = default;
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Title = "EppoApp";
		spec.CommandLineArgs = std::move(args);

		return new EppoApp(spec);
	}
}
