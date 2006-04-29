# New ports collection makefile for:	ipager
# Date created:				22 Mar 2006
# Whom:					Vlad V. Teterya <vlad@vlad.uz.ua>
#
# $FreeBSD$
#

PORTNAME=	ipager
PORTVERSION=	1.1.0
CATEGORIES=	x11
MASTER_SITES=	http://useperl.ru/ipager/src/
DISTNAME=	ipager-${PORTVERSION}

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	X11 pager program

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS+=	Imlib2.3:${PORTSDIR}/graphics/imlib2

USE_X_PREFIX=	yes

PLIST_FILES=	bin/ipager \
		%%DATADIR%%/themes/atlantis.conf \
		%%DATADIR%%/themes/dark_red.conf \
		%%DATADIR%%/themes/green.conf \
		%%DATADIR%%/themes/industrial.conf \
		%%DATADIR%%/themes/light_gray.conf \
		%%DATADIR%%/themes/light_orange.conf
PLIST_DIRS=	%%DATADIR%%/themes %%DATADIR%%
PORTDOCS=	ChangeLog LICENSE README ToDo

THEMES=		atlantis.conf \
		dark_red.conf \
		green.conf \
		industrial.conf \
		light_gray.conf \
		light_orange.conf

post-patch:
	   @${REINPLACE_CMD} -e 's|/usr/local|${X11BASE}|' \
			${WRKSRC}/SConstruct

do-build:
	   @cd ${WRKSRC} && scons

do-install:
	   @cd ${WRKSRC} && scons install

post-install:
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${DATADIR}/themes
.for t in ${THEMES}
	${INSTALL_DATA} ${WRKSRC}/themes/${t} ${DATADIR}/themes
.endfor
	${STRIP_CMD} ${X11BASE}/bin/ipager

	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "     Some additional themes (config files) you may find"
	@${ECHO_MSG} "     in the ${DATADIR}/themes directory."
	@${ECHO_MSG} "     Just copy any of them instead of your ~./ipager/ipager.conf"
	@${ECHO_MSG} "     config file or you can define other config file via '-c'"
	@${ECHO_MSG} "     command line option"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
