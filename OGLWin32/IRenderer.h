//Renderer interface define rendering functions

class IRenderer
{
public:
	IRenderer() {};
	virtual ~IRenderer() {};

	virtual void Init() = 0;
	virtual void Shutdown() = 0; 

	virtual void Render() = 0; 
	virtual void ClearScreen() = 0; 
};

