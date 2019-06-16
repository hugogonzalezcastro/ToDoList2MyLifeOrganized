﻿#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////

using namespace System;

////////////////////////////////////////////////////////////////////////////////////////////////

namespace Abstractspoon
{
	namespace Tdl
	{
		namespace PluginHelpers
		{
			ref class UIThemeToolbarRenderer;
			ref class Translator;

			public ref class HtmlEditorControlEx : MSDN::Html::Editor::HtmlEditorControl
			{
			public:
				HtmlEditorControlEx(Drawing::Font^ controlFont, Translator^ trans);

				void SetUITheme(UITheme^ theme);
				void SetBodyFont(String^ fontName, int pointSize);

				property String^ LastBrowsedImageFolder;
				property String^ LastBrowsedFileFolder;

			protected:
				void SetControlFont(Drawing::Font^ font);
				void SetTranslator(Translator^ trans);

			protected:
				UIThemeToolbarRenderer^ m_toolbarRenderer;
				Drawing::Font^ m_ControlsFont;
				Translator^ m_Trans;

			protected:
				virtual void OnLoad(EventArgs^ args) override;

			protected:
				void InitializeComponentEx();
				void InitialiseFeatures(bool hideDocumentCommands);

				void PreShowDialog(Windows::Forms::Form^ dialog, Drawing::Icon^ icon);
				virtual void PostShowDialog(Windows::Forms::Form^ dialog) override;

				void Translate();
			};
		}
	}
}
