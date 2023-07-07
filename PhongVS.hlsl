cbuffer CBuf
{
	matrix model;
	matrix modelViewProj;
};

struct VertexShaderOut
{
	float3 worldPos : SV_Position;
	float3 normal : Normal;
	float4 pos : SV_Position;
};

VertexShaderOut main(float3 pos : Postition, float3 n : Normal)
{
	VertexShaderOut vso;
	vso.worldPos = (float3) mul(float4(pos, 1.0f), model); 
	vso.normal = mul(n, (float3x3) model);
	vso.pos = mul(float4(pos, 1.0f), modelViewProj);
	return vso;
	

}