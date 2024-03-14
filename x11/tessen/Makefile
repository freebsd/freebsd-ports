PORTNAME=	tessen
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.3
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Interactive menu to autotype and copy pass and gopass data
WWW=		https://github.com/ayushnix/tessen

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	ayushnix

OPTIONS_DEFINE=			DOCS EXAMPLES
OPTIONS_DEFAULT=		GOPASS OPENURL ROFI WLCOPY
OPTIONS_GROUP=			ADDTOOLS
OPTIONS_GROUP_ADDTOOLS=		OPENURL TOTPHOTP
OPTIONS_MULTI=			ACTION_BACKEND
OPTIONS_MULTI_ACTION_BACKEND=	WLCOPY WTYPE
OPTIONS_RADIO=			MENU_BACKEND
OPTIONS_RADIO_MENU_BACKEND=	BEMENU FUZZEL ROFI TOFI WOFI
OPTIONS_SINGLE=			PASS_BACKEND
OPTIONS_SINGLE_PASS_BACKEND=	GOPASS PASS

ACTION_BACKEND_DESC=	Program to copy/autotype data
ADDTOOLS_DESC=		Install additional tools
BEMENU_DESC=		Use bemenu as menu program (wayland)
FUZZEL_DESC=		Use fuzzel as menu program (wayland)
GOPASS_DESC=		Use gopass to access password store
MENU_BACKEND_DESC=	Menu program to show pass entries
OPENURL_DESC=		Open URLs in the default web browser
PASS_BACKEND_DESC=	Program to access password store
PASS_DESC=		Use pass to access password store
ROFI_DESC=		Use rofi as menu program (x11/wayland)
TOFI_DESC=		Use tofi as menu program (wayland)
TOTPHOTP_DESC=		Generate TOTP/HOTP when using pass
WLCOPY_DESC=		Use wl-copy to copy data to clipboard (wayland)
WOFI_DESC=		Use wofi as menu program (wayland)
WTYPE_DESC=		Use wtype to autotype data (wayland)

BEMENU_RUN_DEPENDS=	bemenu:x11/bemenu
DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
FUZZEL_RUN_DEPENDS=	fuzzel:x11/fuzzel
GOPASS_RUN_DEPENDS=	gopass:security/gopass
OPENURL_RUN_DEPENDS=	xdg-open:devel/xdg-utils
PASS_RUN_DEPENDS=	pass:sysutils/password-store
ROFI_RUN_DEPENDS=	rofi:x11/rofi
TOFI_RUN_DEPENDS=	tofi:x11/tofi
TOTPHOTP_RUN_DEPENDS=	pass-otp>=1.2.0:sysutils/pass-otp
WLCOPY_RUN_DEPENDS=	wl-copy:x11/wl-clipboard
WOFI_RUN_DEPENDS=	wofi:x11/wofi
WTYPE_RUN_DEPENDS=	wtype:x11/wtype

do-build:
	@${DO_NADA}

post-build-DOCS-on:
.for s in 1 5
	${LOCALBASE}/bin/scdoc < ${WRKSRC}/man/tessen.${s}.scd > ${WRKSRC}/man/tessen.${s}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tessen ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
.for s in 1 5
	${INSTALL_MAN} ${WRKSRC}/man/tessen.${s} ${STAGEDIR}${PREFIX}/share/man/man${s}/
.endfor

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
