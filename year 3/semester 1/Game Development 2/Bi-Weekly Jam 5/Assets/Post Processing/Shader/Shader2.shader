Shader "Hidden/Shader2"
{
	SubShader
	{
		// No culling or depth
		Cull Off ZWrite Off ZTest Always

		Pass
		{
			HLSLPROGRAM
			#pragma vertex VertDefault
			#pragma fragment Frag
			#include "Packages/com.unity.postprocessing/PostProcessing/Shaders/StdLib.hlsl"

			uniform sampler2D _MainTex;

			uniform float _Power;
			uniform float _Invert;

			float4 Frag(VaryingsDefault i) : SV_Target {
				float4 colour = tex2D(_MainTex, i.texcoord);

				float4 output = float4(1,1,1,1);

				if(colour.r + colour.g + colour.b < 3 / _Power) {
					output = float4(0,0,0,1);
				}

				if(_Invert == 1) {
					output = float4(1 / output.r,1 / output.g,1 / output.g, 1);
				}

				return output;
			}
			ENDHLSL
		}
	}
}

