PORTNAME=	foot
DISTVERSION=	1.10.1
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fast, lightweight and minimalistic Wayland terminal emulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		tllist>=1.0.4:devel/tllist \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig xorg
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS LTO NOTIFY PGO UTF8PROC XDG
OPTIONS_DEFAULT=LTO NOTIFY PGO UTF8PROC XDG
OPTIONS_EXCLUDE+=	${CC:T:Mgcc*:C/.+/LTO/} # undefined reference to `xstrdup'
OPTIONS_EXCLUDE_powerpc64=	${"${/usr/bin/ld:L:tA}"==/usr/bin/ld.lld:?LTO:} # LLVM bug 47353
OPTIONS_EXCLUDE_FreeBSD_12=	${WAYLAND_DISPLAY:UPGO} # ./pgo hangs

DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_MESON_ENABLED=	docs

LTO_MESON_TRUE=		b_lto

NOTIFY_RUN_DEPENDS=	notify-send:devel/libnotify

PGO_USES=		python:build
PGO_MESON_ON=		-Db_pgo=generate
PGO_CFLAGS=		${PGO_CFLAGS_${CHOSEN_COMPILER_TYPE}}
PGO_CFLAGS_clang=	-Wno-ignored-optimization-argument # meson -Db_pgo=use
PGO_SCRIPT_ARGS=	--colors-regular --colors-bright --colors-256 --colors-rgb \
			--scroll --scroll-region \
			--attr-bold --attr-italic --attr-underline \
			--sixel

UTF8PROC_DESC=		Grapheme clustering using libutf8proc
UTF8PROC_LIB_DEPENDS=	libutf8proc.so:textproc/utf8proc
UTF8PROC_MESON_ENABLED=	grapheme-clustering

XDG_DESC=		Open files with xdg-open
XDG_RUN_DEPENDS=	xdg-open:devel/xdg-utils

.if exists(/usr/bin/tic)
# Add site- suffix to avoid conflict with terminfo-db (part of ncurses)
MESON_ARGS+=	-Dcustom-terminfo-install-location="${PLIST_FILES:M*terminfo*:[1]:H:H}"
PKGMESSAGE=	${NONEXISTENT}
PLIST_FILES+=	share/site-terminfo/${PORTNAME:C,^.,&/&,} \
		share/site-terminfo/${PORTNAME:C,^.,&/&,}-direct
.else
MESON_ARGS+=	-Dterminfo=disabled -Ddefault-terminfo=xterm-256color
.endif

.if !defined(DEFAULT_POST_BUILD)
post-build-PGO-on:
	(cd ${BUILD_WRKSRC} && ./${PORTNAME}client --version) # -Wbackend-plugin/-Wmissing-profile
.if defined(WAYLAND_DISPLAY)
# Likely a local build, so optimize for the current config
	(cd ${BUILD_WRKSRC} && LC_ALL=en_US.UTF-8 ./${PORTNAME} ${PYTHON_CMD} \
		${WRKSRC}/scripts/generate-alt-random-writes.py \
		${PGO_SCRIPT_ARGS})
.else
	(cd ${BUILD_WRKSRC} && ./${PORTNAME} --version) # -Wbackend-plugin/-Wmissing-profile
	(cd ${BUILD_WRKSRC} && ${PYTHON_CMD} \
		${WRKSRC}/scripts/generate-alt-random-writes.py \
		--seed=${:!${AWK} '/TIMESTAMP/ { print \$3 }' ${DISTINFO_FILE}!} \
		--rows=67 --cols=135 \
		${PGO_SCRIPT_ARGS} \
		pgo-input && ./pgo pgo-input)
.endif
	@if [ ${CHOSEN_COMPILER_TYPE} = clang ]; then \
		llvm-profdata merge -o ${BUILD_WRKSRC}/default.profdata \
			${BUILD_WRKSRC}/default*.profraw; \
	fi
	${RM} ${BUILD_COOKIE}
	${CONFIGURE_CMD} configure -Db_pgo=use ${BUILD_WRKSRC}
	${MAKE} -C${.CURDIR} build DEFAULT_POST_BUILD=1
.endif

.include <bsd.port.mk>
