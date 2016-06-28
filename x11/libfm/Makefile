# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfm
PORTVERSION=	1.2.4
CATEGORIES=	x11
MASTER_SITES=	SF/pcmanfm/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/LibFM/

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Core library of PCManFM file manager

LICENSE=	LGPL21

.if ! defined(EXTRA_ONLY)
BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		valac:lang/vala
LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libexif.so:graphics/libexif
.endif

SLAVEDIRS=	${CATEGORIES}/${PORTNAME}-extra

USES=		gettext-tools gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --disable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.if ! defined(EXTRA_ONLY)
USES+=		desktop-file-utils shared-mime-info
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--with-gtk=2
.else
USE_GNOME+=	intltool intlhack
CONFIGURE_ARGS+=--with-extra-only
.endif

MICRO_VERSION=	0.4
ABI_VERSION=	4
PLIST_SUB+=	MICRO_VERSION=${MICRO_VERSION} \
		ABI_VERSION=${ABI_VERSION}

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	${REINPLACE_CMD} -e 's|^[[:blank:]]\{5,\}USE_NLS=yes|#&|' \
		${WRKSRC}/configure

	${REINPLACE_CMD} -e '/^pkgincludedir/s|-@FMLIBVER@||; \
		/@LN_S@ @PACKAGE@-@FMLIBVER@/d' \
		${WRKSRC}/src/Makefile.in

.if ! defined(EXTRA_ONLY)
	${REINPLACE_CMD} -e 's|DATA = libfm-extra.pc|DATA =|' \
		${WRKSRC}/Makefile.in

	${REINPLACE_CMD} -e '/^LIBFM_EXTRA_INCLUDES/,+4 s|^|@EXTRALIB_ONLY_TRUE@|; \
		/FALSE@lib_LTLIBRARIES/s| libfm-extra.la||; \
		s|libfm-extra.la \\|-lfm-extra \\|' \
		${WRKSRC}/src/Makefile.in

	${REINPLACE_CMD} -e 's|-@FMLIBVER@||' ${WRKSRC}/src/actions/Makefile.in

	${REINPLACE_CMD} -e '/^vfs_menu_la_DEPENDENCIES/{s| \\||;n;d;}; \
		/^vfs_menu_la_LIBADD/s|$$(top.*|-lfm-extra|' \
		${WRKSRC}/src/modules/Makefile.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}/${PORTNAME}.conf.sample

	${INSTALL_DATA} ${WRKSRC}/src/actions/fm-actions.h \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
