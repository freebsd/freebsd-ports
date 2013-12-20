# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmii
DISTVERSION=	3.9.2
CATEGORIES=	x11-wm
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-devel
DISTNAME=	wmii+ixp-${DISTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic, minimalist window manager for X11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libixp.so:${PORTSDIR}/devel/libixp

OPTIONS_DEFINE=	DOCS

CONFLICTS=	wmii-3.6*

USE_BZIP2=	yes
USES=		pkgconfig
USE_XORG=	x11 xext xrandr xrender xinerama xft
USE_LDCONFIG=	yes
MAKE_ENV=	noisycc=1	# unmute build commands, useful for logs
MAKE_ARGS=	PREFIX="${PREFIX}" INCLUDE="${LOCALBASE}/include" \
		CC="${CC} -c" LD="${CC}" LIBIXP="-lixp" \
		STATIC="" MAN="${MANPREFIX}/man" DOC="${DOCSDIR}"

.include <bsd.port.options.mk>

post-patch:
# Link against `devel/libixp' from ports and drop extraneous build options
	@${REINPLACE_CMD} -e '/libixp/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/lib,${LOCALBASE}/lib, ; /^CFLAGS +=/d' \
		${WRKSRC}/config.mk

do-install:
.for i in wmii9menu wmiir
	(cd ${WRKSRC}/cmd && ${INSTALL_PROGRAM} ${i}.out \
		${STAGEDIR}${PREFIX}/bin/${i})
.endfor
.for i in wmii.rc wmii.sh
	(cd ${WRKSRC}/cmd && ${INSTALL_DATA} ${i}.out \
		${STAGEDIR}${PREFIX}/bin/${i})
.endfor
	(cd ${WRKSRC}/cmd && ${INSTALL_SCRIPT} wihack.out \
		${STAGEDIR}${PREFIX}/bin/wihack)
	(cd ${WRKSRC}/cmd/menu && ${INSTALL_PROGRAM} wimenu.out \
		${STAGEDIR}${PREFIX}/bin/wimenu)
	(cd ${WRKSRC}/cmd/wmii && ${INSTALL_PROGRAM} wmii.out \
		${STAGEDIR}${PREFIX}/bin/wmii)
	(cd ${WRKSRC}/lib && ${INSTALL_LIB} libwmii_hack.so \
		${STAGEDIR}${PREFIX}/lib)
	(cd ${WRKSRC}/man && ${INSTALL_MAN} *.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in welcome wmiirc
	(cd ${WRKSRC}/rc && ${INSTALL_DATA} ${i}.out \
		${STAGEDIR}${ETCDIR}/${i})
.endfor
	@${MKDIR} ${STAGEDIR}${ETCDIR}/plan9port
	(cd ${WRKSRC}/alternative_wmiircs/plan9port && ${INSTALL_DATA} wmiirc \
		${STAGEDIR}${ETCDIR}/plan9port)
	@${MKDIR} ${STAGEDIR}${ETCDIR}/python
.for i in wmiirc wmiirc.py
	(cd ${WRKSRC}/alternative_wmiircs/python && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${ETCDIR}/python)
.endfor
	@${MKDIR} ${STAGEDIR}${ETCDIR}/python/pygmi
	(cd ${WRKSRC}/alternative_wmiircs/python/pygmi && ${INSTALL_DATA} *.py \
		${STAGEDIR}${ETCDIR}/python/pygmi)
	@${MKDIR} ${STAGEDIR}${ETCDIR}/python/pyxp
	(cd ${WRKSRC}/alternative_wmiircs/python/pyxp && ${INSTALL_DATA} *.py \
		${STAGEDIR}${ETCDIR}/python/pyxp)
	@${MKDIR} ${STAGEDIR}${ETCDIR}/ruby
.for i in config.rb config.yaml wmiirc
	(cd ${WRKSRC}/alternative_wmiircs/ruby && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${ETCDIR}/ruby)
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in LICENSE README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} wmii.pdf ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/alternative_wmiircs
	(cd ${WRKSRC}/alternative_wmiircs && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR}/alternative_wmiircs)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/alternative_wmiircs/plan9port
	(cd ${WRKSRC}/alternative_wmiircs/plan9port && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR}/alternative_wmiircs/plan9port)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/alternative_wmiircs/python
	(cd ${WRKSRC}/alternative_wmiircs/python && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR}/alternative_wmiircs/python)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/alternative_wmiircs/ruby
.for i in HISTORY LICENSE README
	(cd ${WRKSRC}/alternative_wmiircs/ruby && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR}/alternative_wmiircs/ruby)
.endfor

.include <bsd.port.mk>
