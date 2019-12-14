using System;
using UnityEngine;
using UnityEngine.Rendering.PostProcessing;

[Serializable, PostProcess(typeof(CustomShaderRenderer), PostProcessEvent.AfterStack, "Custom/CustomShader", true)]
public sealed class CustomShader : PostProcessEffectSettings {
    public FloatParameter power = new FloatParameter() { value = 0 };
    public BoolParameter invert = new BoolParameter() { value = false };

}

public sealed class CustomShaderRenderer : PostProcessEffectRenderer<CustomShader> {
    public override void Render(PostProcessRenderContext context) {
        var sheet = context.propertySheets.Get(Shader.Find("Hidden/Shader2"));
        sheet.properties.SetFloat("_Power", settings.power);
        float f = 0;
        if(settings.invert) {
            f = 1;
        }
        sheet.properties.SetFloat("_Invert", f);
        context.command.BlitFullscreenTriangle(context.source, context.destination, sheet, 0);
    }
}

