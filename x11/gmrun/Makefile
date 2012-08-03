# New ports collection makefile for:	gmrun
# Date created:				26 September 2002
# Whom:					Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	gmrun
PORTVERSION=	0.9.2
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A customizable program to run programs, with tab-completion

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-stlport

PORTDOCS=	README
PLIST_FILES=	bin/gmrun %%DATADIR%%/gmrunrc
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

post-patch:
.if ( ${OSVERSION} >= 800501 && ${OSVERSION} < 900000 ) || ( ${OSVERSION} >= 900006 )
	@${REINPLACE_CMD} -e '/my_alphasort/s#const void\*#const struct dirent**#g' \
		${WRKSRC}/src/gtkcompletionline.cc
.else
	@${REINPLACE_CMD} -e '/select_executables_only(const /s#const ##' \
		${WRKSRC}/src/gtkcompletionline.cc
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
