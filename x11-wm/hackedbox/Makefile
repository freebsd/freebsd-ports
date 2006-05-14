# New ports collection makefile for:	hackedbox
# Date created:				2002-05-11
# Whom:				Dominic Marks <dominic.marks@btinternet.com>
# based on the blackbox and openbox ports
#
# $FreeBSD$
#

PORTNAME=	hackedbox
PORTVERSION=	0.8.4
CATEGORIES=	x11-wm
MASTER_SITES=	http://scrudgeware.org/downloads/hackedbox/

MAINTAINER=	dominic.marks@btinternet.com
COMMENT=	Hackedbox is a small and fast window manager based on Blackbox

MAN1=		hackedbox.1
DOCS=		AUTHORS ChangeLog INSTALL README TODO
I10L=		C da_DK de_DE es_ES fr_FR it_IT nl_NL pt_BR ru_RU sl_SI \
			sv_SE tr_TR
STYLES=		artwiz bluebox cthulhain deep flux frobozz frobust nyz \
			nyzclone operation outcomes shade steelblue \
			steelblue2 the_orange trisb twice
PLIST=		${WRKDIR}/pkg-plist
#USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-bg-utils

pre-patch:
	${REINPLACE_CMD} -e \
		"s:/usr/local/share/hackedbox:${PREFIX}/share/hackedbox:g" \
		${WRKSRC}/data/menu.in
	${REINPLACE_CMD} -e \
		"s:blackbox:hackedbox:g; s:Blackbox:Hackedbox:g; \
		s:bsetroot:hsetroot:g; s:Bsetroot:Hsetroot:g" \
		${WRKSRC}/data/styles/*

pre-install:
	${RM} -f ${PLIST}
.for ii in hsetroot hackedbox
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} share/hackedbox/menu >> ${PLIST}
.for ii in ${I10L}
	${ECHO_CMD} share/hackedbox/nls/${ii}/hackedbox.cat >> ${PLIST}
	${ECHO_CMD} @dirrm share/hackedbox/nls/${ii} >> ${PLIST}
.endfor
.for ii in ${STYLES}
	${ECHO_CMD} share/hackedbox/styles/${ii} >> ${PLIST}
.endfor
.for ii in /backgrounds /styles /nls /
	${ECHO_CMD} @dirrm share/hackedbox${ii} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/hackedbox/${ii} >> ${PLIST}
.endfor
.for ii in nl_NL sl_SI
	${ECHO_CMD} @dirrm share/doc/hackedbox/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/hackedbox >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/util/bsetroot ${PREFIX}/bin/hsetroot
	${INSTALL_PROGRAM} ${WRKSRC}/src/hackedbox ${PREFIX}/bin/hackedbox
	${MKDIR} ${DATADIR}/styles ${DATADIR}/backgrounds
	${INSTALL_DATA} ${WRKSRC}/data/menu ${DATADIR}
.for ii in ${I10L}
	${MKDIR} ${PREFIX}/share/hackedbox/nls/${ii}/
	${INSTALL_DATA} ${WRKSRC}/nls/${ii}/blackbox.cat \
		${PREFIX}/share/hackedbox/nls/${ii}/hackedbox.cat
.endfor

.for ii in ${BACKGROUNDS}
	${INSTALL_DATA} ${WRKSRC}/data/backgrounds/${ii} \
		${PREFIX}/share/hackedbox/backgrounds/
.endfor
.for ii in ${STYLES}
	${INSTALL_DATA} ${WRKSRC}/data/styles/${ii} \
		${PREFIX}/share/hackedbox/styles/
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/hackedbox.1 ${PREFIX}/man/man1/hackedbox.1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/nl_NL ${DOCSDIR}/sl_SI
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
