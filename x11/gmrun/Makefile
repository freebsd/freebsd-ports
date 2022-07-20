PORTNAME=	gmrun
PORTVERSION=	0.9.2
PORTREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Customizable program to run programs, with tab-completion

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpopt.so:devel/popt

USES=		compiler:c++11-lang gmake gnome localbase:ldflags pkgconfig

USE_GNOME=	cairo gdkpixbuf2 gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-stlport

PLIST_FILES=	bin/gmrun ${DATADIR}/gmrunrc
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/my_alphasort/s#const void\*#const struct dirent**#g' \
		${WRKSRC}/src/gtkcompletionline.cc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
